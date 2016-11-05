#pragma once

namespace pipe { namespace algorithm {

template <typename T, typename Algorithm>
auto operator|(generator_t<T>& gen, Algorithm algorithm)
{
    return algorithm(std::move(gen));
}

}} // namespace pipe::algorithm
