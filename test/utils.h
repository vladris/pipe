#pragma once
#include <experimental/generator>
#include <vector>

template <typename T = int>
auto generate(std::vector<T> vec)
{
    for (auto&& item : vec)
        co_yield item;
}