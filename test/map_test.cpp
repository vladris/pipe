#include <iterator>

#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::functional;
using namespace pipe::generator;

TEST_GROUP(map_test)
{
    TEST(map_zero_items)
    {
        std::vector<int> out { };
        std::vector<int> { } | to_generator() | map(identity { }) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(map_multiple_items)
    {
        std::vector<int> out { };
        count<int>() | take_n(3) | map([](auto& item) { return item * 2; }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(0, out[0]);
        test::assert::equals(2, out[1]);
        test::assert::equals(4, out[2]);
    }

};