#pragma once

#include <cstddef>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "libime/pinyin/pinyinime.h"

namespace libime {
class PinyinContext;
}

namespace dump {

using PreeditResult =
    std::tuple<std::string, size_t, std::vector<std::pair<size_t, size_t>>>;

PreeditResult
preeditWithCursorHighlightImpl(const libime::PinyinContext &context,
                               libime::PinyinPreeditMode mode,
                               size_t inputCursor);

} // namespace dump
