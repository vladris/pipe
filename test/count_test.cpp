#include <iterator>

#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(count_test)
{
    TEST(count_generator)
    {
        std::vector<size_t> out { };
        count() | take_n(3) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(0, out[0]);
        test::assert::equals(1, out[1]);
        test::assert::equals(2, out[2]);
    }

    TEST(count_generator_custom_type)
    {
        std::vector<int32_t> out { };
        count<int32_t>(-2) | take_n(3) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::equals(-2, out[0]);
        test::assert::equals(-1, out[1]);
        test::assert::equals(0, out[2]);
    }
};