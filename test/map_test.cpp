#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(map_test)
{
    TEST(map_zero_items)
    {
        auto result = generate({}) | map([](auto& item) { return item; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }

    TEST(map_multiple_items)
    {
        auto result = generate({ 1, 2, 3 }) | map([](auto& item) { return item * 2; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::equals(2, vec[0]);
        test::assert::equals(4, vec[1]);
        test::assert::equals(6, vec[2]);
    }

};