#include <cstddef>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

#include <fcitx-utils/macros.h>
#include <libime/core/historybigram.h>
#include <libime/core/inputbuffer.h>
#include <libime/core/languagemodel.h>
#include <libime/core/lattice.h>
#include <libime/pinyin/libimepinyin_export.h>
#include <libime/pinyin/pinyinencoder.h>
#include <libime/pinyin/pinyinime.h>

#define private public
#include <libime/pinyin/pinyincontext.h>
#undef private

#include "dump_access.h"

namespace dump {

PreeditResult
preeditWithCursorHighlightImpl(const libime::PinyinContext &context,
                               libime::PinyinPreeditMode mode,
                               size_t inputCursor) {
    return context.preeditWithCursorHighlightImpl(mode, inputCursor);
}

} // namespace dump
