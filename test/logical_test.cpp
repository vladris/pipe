#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::functional;
using namespace pipe::generator;

TEST_GROUP(logical_test)
{
    TEST(all_zero_items)
    {
        auto value = repeat(constant(42)) | take_n(0) | all(constant(false));

        test::assert::is_true(value);
    }

    TEST(all_true_for_no_items)
    {
        auto value = count() | take_n(6) | all(constant(false));

        test::assert::is_false(value);
    }

    TEST(all_true_for_all_items)
    {
        auto value = count() | take_n(6) | all(constant(true));

        test::assert::is_true(value);
    }

    TEST(all_true_for_some_items)
    {
        auto value = count() | take_n(6) | all([](auto& i) { return i < 4; });

        test::assert::is_false(value);
    }

    TEST(none_zero_items)
    {
        auto value = repeat(constant(42)) | take_n(0) | none(constant(false));

        test::assert::is_true(value);
    }

    TEST(none_true_for_no_items)
    {
        auto value = count() | take_n(6) | none(constant(false));

        test::assert::is_true(value);
    }

    TEST(none_true_for_all_items)
    {
        auto value = count() | take_n(6) | none(constant(true));

        test::assert::is_false(value);
    }

    TEST(none_true_for_some_items)
    {
        auto value = count() | take_n(6) | none([](auto& i) { return i < 4; });

        test::assert::is_false(value);
    }

    TEST(some_zero_items)
    {
        auto value = repeat(constant(42)) | take_n(0) | some(constant(false));

        test::assert::is_false(value);
    }

    TEST(some_true_for_no_items)
    {
        auto value = count() | take_n(6) | some(constant(false));

        test::assert::is_false(value);
    }

    TEST(some_true_for_all_items)
    {
        auto value = count() | take_n(6) | some(constant(true));

        test::assert::is_true(value);
    }

    TEST(some_true_for_some_items)
    {
        auto value = count() | take_n(6) | some([](auto& i) { return i < 4; });

        test::assert::is_true(value);
    }
};