#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(numeric_test)
{
    TEST(min_zero_items)
    {
        auto value = generate({}) | min();
        test::assert::equals(0, value);
    }

    TEST(min_one_item)
    {
        auto value = generate({ -42 }) | min();
        test::assert::equals(-42, value);
    }

    TEST(min_multiple_items)
    {
        auto value = generate({ 3, 2, 1, 4, 5 }) | min();
        test::assert::equals(1, value);
    }

    TEST(max_zero_items)
    {
        auto value = generate({}) | max();
        test::assert::equals(0, value);
    }

    TEST(max_one_item)
    {
        auto value = generate({ -42 }) | max();
        test::assert::equals(-42, value);
    }

    TEST(max_multiple_items)
    {
        auto value = generate({ 3, 2, 5, 4, 1 }) | max();
        test::assert::equals(5, value);
    }

    TEST(length_zero_items)
    {
        auto value = generate({}) | length();
        test::assert::equals(0, value);
    }

    TEST(length_one_item)
    {
        auto value = generate({ -42 }) | length();
        test::assert::equals(1, value);
    }

    TEST(length_multiple_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5, 6 }) | length();
        test::assert::equals(6, value);
    }
};