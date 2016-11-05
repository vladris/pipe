#pragma once
#include <experimental/generator>

namespace pipe {

template <typename T> using generator_t = std::experimental::generator<T>;

} // namespace pipe
