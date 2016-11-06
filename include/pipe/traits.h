#pragma once
#include <experimental/generator>

namespace pipe {

template <typename T>
struct is_generator
{
    static const bool value = false;
};

template <typename T, typename Allocator>
struct is_generator<std::experimental::generator<T, Allocator>>
{
    static const bool value = true;
};

} // namespace pipe
