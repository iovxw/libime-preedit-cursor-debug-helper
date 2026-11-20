#include <cstdlib>
#include <cstring>
#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <unistd.h>

#include "libime/core/historybigram.h"
#include "libime/core/userlanguagemodel.h"
#include "libime/pinyin/pinyincontext.h"
#include "libime/pinyin/pinyindictionary.h"
#include "libime/pinyin/pinyinencoder.h"
#include "libime/pinyin/pinyinime.h"
#include "libime/pinyin/shuangpinprofile.h"

#include "dump_access.h"

using namespace libime;

namespace {

std::string withCursor(std::string s, size_t pos) {
    if (pos > s.size()) {
        pos = s.size();
    }
    s.insert(s.begin() + pos, '|');
    return s;
}

// Re-exec once with the requested libIMEPinyin preloaded. Because the
// executable's NEEDED entry is "libIMEPinyin.so.0", LD_PRELOAD makes the
// dynamic loader use the requested file for that SONAME.
void reexecWithPreload(const char *library, char **argv) {
    setenv("LD_PRELOAD", library, 1);
    setenv("DUMP_LIBIME_REEXEC", "1", 1);

    char exe[4096];
    ssize_t n = readlink("/proc/self/exe", exe, sizeof(exe) - 1);
    if (n > 0) {
        exe[n] = '\0';
    } else {
        std::strncpy(exe, "dump", sizeof(exe));
        exe[sizeof(exe) - 1] = '\0';
    }

    // argv is intentionally reused as-is.
    execv(exe, argv);
    perror("execv");
    std::exit(1);
}

} // namespace

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "usage: " << argv[0]
                  << " <libime-build-dir> <input>\n";
        return 1;
    }

    const std::string buildDir = argv[1];
    const std::string library =
        (std::filesystem::path(buildDir) / "bin" / "libIMEPinyin.so").string();
    const std::string lmPath =
        (std::filesystem::path(buildDir) / "data" / "sc.lm").string();
    const std::string dictPath =
        (std::filesystem::path(buildDir) / "data" / "sc.dict").string();

    if (!std::getenv("DUMP_LIBIME_REEXEC")) {
        reexecWithPreload(library.c_str(), argv);
    }

    const std::string input = argv[2];

    Dl_info info{};
    if (void *sym = dlsym(RTLD_DEFAULT,
                          "_ZNK6libime13PinyinContext30"
                          "preeditWithCursorHighlightImplB5cxx11ENS_17"
                          "PinyinPreeditModeEm");
        sym && dladdr(sym, &info) && info.dli_fname) {
        std::cout << "lib: " << info.dli_fname << "\n";
    } else {
        std::cout << "lib: " << library << " (dladdr failed)\n";
    }

    PinyinIME ime(
        std::make_unique<PinyinDictionary>(),
        std::make_unique<UserLanguageModel>(
            lmPath.c_str()));
    ime.dict()->load(PinyinDictionary::SystemDict, dictPath.c_str(),
                     PinyinDictFormat::Binary);
    ime.setShuangpinProfile(std::make_shared<ShuangpinProfile>(
        ShuangpinBuiltinProfile::Ziranma));

    PinyinContext c(&ime);
    c.setUseShuangpin(true);
    c.type(input);

    const auto mode = PinyinPreeditMode::Pinyin;
    for (size_t real = 0; real <= c.size(); ++real) {
        c.setCursor(real);
        std::cout << "=== real cursor " << real << " : "
                  << withCursor(input, real) << " ===\n";

        auto [realPreedit, realCursor, realHighlights] =
            c.preeditWithCursorHighlight(mode);
        (void)realHighlights;
        std::cout << "public preedit: "
                  << withCursor(realPreedit, realCursor) << "\n";

        std::cout << "forward (virtual cursor -> preedit):\n";
        for (size_t v = 0; v <= c.size(); ++v) {
            auto [preedit, pcursor, highlights] =
                dump::preeditWithCursorHighlightImpl(c, mode, v);
            (void)highlights;
            std::cout << "  " << withCursor(input, v) << "  v=" << v
                      << "  ->  " << withCursor(preedit, pcursor) << "\n";
        }

        std::cout << "reverse (preedit cursor -> input):\n";
        auto [preedit, pcursor, highlights] =
            dump::preeditWithCursorHighlightImpl(c, mode, real);
        (void)pcursor;
        (void)highlights;
        for (size_t p = 0; p <= preedit.size(); ++p) {
            auto target = c.cursorForPreeditPosition(p, mode);
            std::cout << "  " << withCursor(preedit, p) << "  ->  "
                      << (target ? withCursor(input, *target)
                                 : std::string("(selected/none)"))
                      << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}
