#include <iterator>

#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::functional;
using namespace pipe::generator;

TEST_GROUP(filter_test)
{
    TEST(filter_zero_items)
    {
        std::vector<int> out { };
        std::vector<int> { } | to_generator() | filter(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(filter_none_selected)
    {
        std::vector<int> out { };
        count<int>() | take_n(7) | filter(constant(false)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(filter_some_selected)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | filter([](auto& item) { return item % 2 == 0; }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(0, out[0]);
        test::assert::equals(2, out[1]);
        test::assert::equals(4, out[2]);
    }

    TEST(filter_all_selected)
    {
        std::vector<int> out { };
        count<int>() | take_n(6) | filter(constant(true)) | collect(std::back_inserter(out));

        test::assert::equals(6, out.size());
    }
};