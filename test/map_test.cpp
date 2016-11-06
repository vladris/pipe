#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(map_test)
{
    TEST(map_zero_items)
    {
        std::vector<int> in { };
        auto result = in | to_generator() | map([](auto& item) { return item; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(map_multiple_items)
    {
        auto result = count<int>() | take_n(3) | map([](auto& item) { return item * 2; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(0, vec[0]);
        test::assert::equals(2, vec[1]);
        test::assert::equals(4, vec[2]);
    }

};