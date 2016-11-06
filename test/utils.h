#pragma once
#include <experimental/generator>
#include <vector>

inline auto generate(std::vector<int> vec)
{
    for (auto&& item : vec)
        co_yield item;
}