#pragma once
#include <pipe/functional/counter.h>
#include <pipe/generator/repeat.h>

namespace pipe { namespace generator {

template <typename T = size_t, template <typename, typename> typename Generator = std::experimental::generator, typename Allocator = std::allocator<char>>
auto count(T initial_value = T {}) -> Generator<T, Allocator>
{
    return repeat<Generator, Allocator>(pipe::functional::counter<T>(initial_value));
}

}} // namespace pipe::generator
