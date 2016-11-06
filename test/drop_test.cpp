#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(drop_test)
{
    TEST(drop_while_zero_items)
    {
        auto result = generate({}) | drop_while([](auto&) { return true; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }

    TEST(drop_while_no_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_while([](auto&) { return false; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(6, vec.size());
    }

    TEST(drop_while_some_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_while([](auto& item) { return item < 4; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::equals(4, vec[0]);
        test::assert::equals(5, vec[1]);
        test::assert::equals(6, vec[2]);
    }

    TEST(drop_while_all_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_while([](auto& item) { return true; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }

    TEST(drop_until_zero_items)
    {
        auto result = generate({}) | drop_until([](auto&) { return true; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }

    TEST(drop_until_no_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_until([](auto&) { return true; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(6, vec.size());
    }

    TEST(drop_until_some_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_until([](auto& item) { return item > 3; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::equals(4, vec[0]);
        test::assert::equals(5, vec[1]);
        test::assert::equals(6, vec[2]);
    }

    TEST(drop_until_all_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_until([](auto& item) { return false; });

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }

    TEST(drop_n_zero_items)
    {
        auto result = generate({}) | drop_n(42);

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }

    TEST(drop_n_some_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_n(3);

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::equals(4, vec[0]);
        test::assert::equals(5, vec[1]);
        test::assert::equals(6, vec[2]);
    }

    TEST(drop_n_all_items)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) | drop_n(42);

        std::vector<int> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }
};