#include <iterator>

#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::functional;
using namespace pipe::generator;

TEST_GROUP(take_test)
{
    TEST(take_while_zero_items)
    {
        std::vector<int> out {};
        std::vector<int> { } | to_generator() | take_while(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(take_while_no_items)
    {
        std::vector<int> out { };
        std::vector<int> { 1, 2, 3 } | to_generator() | take_while(constant(false)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(take_while_some_items)
    {
        std::vector<int> out { };
        std::vector<int> { 1, 2, 3, 4, 5, 6 } | to_generator() | take_while([](auto& item) { return item < 4; }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(1, out[0]);
        test::assert::equals(2, out[1]);
        test::assert::equals(3, out[2]);
    }

    TEST(take_while_all_items)
    {
        std::vector<int> out { };
        std::vector<int> { 1, 2, 3, 4, 5, 6 } | to_generator() | take_while(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(6, out.size());
    }

    TEST(take_until_zero_items)
    {
        std::vector<int> out { };
        std::vector<int> { } | to_generator() | take_until(constant(false)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(take_until_no_items)
    {
        std::vector<int> out { };
        std::vector<int> { 1, 2, 3 } | to_generator() | take_until(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(take_until_some_items)
    {
        std::vector<int> out { };
        std::vector<int> { 1, 2, 3, 4, 5, 6 } | to_generator() | take_until([](auto& item) { return item > 3; }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(1, out[0]);
        test::assert::equals(2, out[1]);
        test::assert::equals(3, out[2]);
    }

    TEST(take_until_all_items)
    {
        std::vector<int> out { };
        std::vector<int> { 1, 2, 3, 4, 5, 6 } | to_generator() | take_until(constant(false)) | collect(std::back_inserter(out));

        test::assert::equals(6, out.size());
    }

    TEST(take_n_zero_items)
    {
        std::vector<int> out { };
        std::vector<int> { } | to_generator() | take_n(42) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(take_n_some_items)
    {
        std::vector<int> out { };
        std::vector<int> { 1, 2, 3, 4, 5, 6 } | to_generator() | take_n(3) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(1, out[0]);
        test::assert::equals(2, out[1]);
        test::assert::equals(3, out[2]);
    }

    TEST(take_n_all_items)
    {
        std::vector<int> out {};
        std::vector<int> { 1, 2, 3, 4, 5, 6 } | to_generator() | take_n(42) | collect(std::back_inserter(out));

        test::assert::equals(6, out.size());
    }
};