#pragma once
#include <experimental/generator>
#include <memory>
#include <type_traits>

namespace pipe { namespace generator {

template <template <typename, typename> typename Generator = std::experimental::generator, typename Allocator = std::allocator<char>, typename Func>
auto repeat(Func func) -> Generator<typename std::result_of<Func()>::type, Allocator>
{
    for (;;)
        co_yield func();
}

}} // namespace pipe::generator
