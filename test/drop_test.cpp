#include <iterator>

#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::functional;
using namespace pipe::generator;

TEST_GROUP(drop_test)
{
    TEST(drop_while_zero_items)
    {
        std::vector<int> out { };
        std::vector<int> { } | to_generator() | drop_while(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(drop_while_no_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | drop_while(constant(false)) | collect(std::back_inserter(out));

        test::assert::equals(6, out.size());
    }

    TEST(drop_while_some_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | drop_while([](auto& item) { return item < 3; }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(3, out[0]);
        test::assert::equals(4, out[1]);
        test::assert::equals(5, out[2]);
    }

    TEST(drop_while_all_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | drop_while(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(drop_until_zero_items)
    {
        std::vector<int> out { };
        std::vector<int> { } | to_generator() | drop_until(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(drop_until_no_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | drop_until(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(6, out.size());
    }

    TEST(drop_until_some_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | drop_until([](auto& item) { return item > 2; }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(3, out[0]);
        test::assert::equals(4, out[1]);
        test::assert::equals(5, out[2]);
    }

    TEST(drop_until_all_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | drop_until(constant(false)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(drop_n_zero_items)
    {
        std::vector<int> out { };
        std::vector<int> { } | to_generator() | drop_n(42) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(drop_n_some_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | drop_n(3) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(3, out[0]);
        test::assert::equals(4, out[1]);
        test::assert::equals(5, out[2]);
    }

    TEST(drop_n_all_items)
    {
        std::vector<int> out {};
        count<int>() | take_n(6) | drop_n(42) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }
};