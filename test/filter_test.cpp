#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(filter_test)
{
    TEST(filter_zero_items)
    {
        auto result = std::vector<int> {} | to_generator() | filter([](auto&) { return true; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(filter_none_selected)
    {
        auto result = count<int>() | take_n(7) | filter([](auto& item) { return item > 42; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(filter_some_selected)
    {
        auto result = count<int>() | take_n(6) | filter([](auto& item) { return item % 2 == 0; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(0, vec[0]);
        test::assert::equals(2, vec[1]);
        test::assert::equals(4, vec[2]);
    }

    TEST(filter_all_selected)
    {
        auto result = count<int>() | take_n(6) | filter([](auto& item) { return item < 42; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(6, vec.size());
    }
};