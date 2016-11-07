#include <iterator>

#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(collect_test)
{
    TEST(collect_no_items)
    {
        std::vector<int> out {};
        count<int>() | take_n(0) | collect(std::back_inserter(out));

        test::assert::is_true(out.empty());
    }

    TEST(collect_multiple_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(5) | collect(std::back_inserter(out));

        test::assert::equals(5, out.size());
    }
};