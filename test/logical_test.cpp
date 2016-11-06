#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(logical_test)
{
    TEST(all_zero_items)
    {
        auto value = generate({}) | all([](auto&) { return false; });
        test::assert::is_true(value);
    }

    TEST(all_true_for_no_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | all([](auto& i) { return i > 42; });
        test::assert::is_false(value);
    }

    TEST(all_true_for_all_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | all([](auto& i) { return i < 42; });
        test::assert::is_true(value);
    }

    TEST(all_true_for_some_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | all([](auto& i) { return i < 4; });
        test::assert::is_false(value);
    }

    TEST(none_zero_items)
    {
        auto value = generate({}) | none([](auto&) { return false; });
        test::assert::is_true(value);
    }

    TEST(none_true_for_no_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | none([](auto& i) { return i > 42; });
        test::assert::is_true(value);
    }

    TEST(none_true_for_all_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | none([](auto& i) { return i < 42; });
        test::assert::is_false(value);
    }

    TEST(none_true_for_some_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | none([](auto& i) { return i < 4; });
        test::assert::is_false(value);
    }

    TEST(some_zero_items)
    {
        auto value = generate({}) | some([](auto&) { return false; });
        test::assert::is_false(value);
    }

    TEST(some_true_for_no_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | some([](auto& i) { return i > 42; });
        test::assert::is_false(value);
    }

    TEST(some_true_for_all_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | some([](auto& i) { return i < 42; });
        test::assert::is_true(value);
    }

    TEST(some_true_for_some_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | some([](auto& i) { return i < 4; });
        test::assert::is_true(value);
    }
};