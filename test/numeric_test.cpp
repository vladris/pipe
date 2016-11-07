#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(numeric_test)
{
    TEST(min_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | min();

        test::assert::equals(0, value);
    }

    TEST(min_one_item)
    {
        std::vector<int> in { 42 };
        auto value = in | to_generator() | min();

        test::assert::equals(42, value);
    }

    TEST(min_multiple_items)
    {
        std::vector<int> in { 3, 2, 1, 4, 5 };
        auto value = in | to_generator() | min();

        test::assert::equals(1, value);
    }

    TEST(max_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | max();

        test::assert::equals(0, value);
    }

    TEST(max_one_item)
    {
        std::vector<int> in { -42 };
        auto value = in | to_generator() | max();

        test::assert::equals(-42, value);
    }

    TEST(max_multiple_items)
    {
        std::vector<int> in { 3, 2, 5, 4, 1 };
        auto value = in | to_generator() | max();
        test::assert::equals(5, value);
    }

    TEST(length_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | length();

        test::assert::equals(0, value);
    }

    TEST(length_one_item)
    {
        std::vector<int> in { -42 };
        auto value = in | to_generator() | length();

        test::assert::equals(1, value);
    }

    TEST(length_multiple_items)
    {
        auto value = count() | take_n(6) | length();

        test::assert::equals(6, value);
    }
};