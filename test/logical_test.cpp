#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(logical_test)
{
    TEST(all_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | all([](auto&) { return false; });
        test::assert::is_true(value);
    }

    TEST(all_true_for_no_items)
    {
        auto value = count() | take_n(6) | all([](auto& i) { return i > 42; });
        test::assert::is_false(value);
    }

    TEST(all_true_for_all_items)
    {
        auto value = count() | take_n(6) | all([](auto& i) { return i < 42; });
        test::assert::is_true(value);
    }

    TEST(all_true_for_some_items)
    {
        auto value = count() | take_n(6) | all([](auto& i) { return i < 4; });
        test::assert::is_false(value);
    }

    TEST(none_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | none([](auto&) { return false; });
        test::assert::is_true(value);
    }

    TEST(none_true_for_no_items)
    {
        auto value = count() | take_n(6) | none([](auto& i) { return i > 42; });
        test::assert::is_true(value);
    }

    TEST(none_true_for_all_items)
    {
        auto value = count() | take_n(6) | none([](auto& i) { return i < 42; });
        test::assert::is_false(value);
    }

    TEST(none_true_for_some_items)
    {
        auto value = count() | take_n(6) | none([](auto& i) { return i < 4; });
        test::assert::is_false(value);
    }

    TEST(some_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | some([](auto&) { return false; });
        test::assert::is_false(value);
    }

    TEST(some_true_for_no_items)
    {
        auto value = count() | take_n(6) | some([](auto& i) { return i > 42; });
        test::assert::is_false(value);
    }

    TEST(some_true_for_all_items)
    {
        auto value = count() | take_n(6) | some([](auto& i) { return i < 42; });
        test::assert::is_true(value);
    }

    TEST(some_true_for_some_items)
    {
        auto value = count() | take_n(6) | some([](auto& i) { return i < 4; });
        test::assert::is_true(value);
    }
};