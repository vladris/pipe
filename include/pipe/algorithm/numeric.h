#pragma once
#include <algorithm>
#include <pipe/algorithm/accumulate.h>
#include <pipe/algorithm/fold.h>
#include <pipe/functional.h>

namespace pipe { namespace algorithm {

inline auto min()
{
    return fold([](auto& a, auto& b) { return std::min(a, b); });
}

inline auto max()
{
    return fold([](auto& a, auto& b) { return std::max(a, b); });
}

inline auto count()
{
    return accumulate(size_t(0), pipe::functional::counter(1));
}

}} // namespace pipe::algorithm
