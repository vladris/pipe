#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(count_test)
{
    TEST(count_generator)
    {
        auto result = count() | take_n(3);

        std::vector<size_t> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::equals(0, vec[0]);
        test::assert::equals(1, vec[1]);
        test::assert::equals(2, vec[2]);
    }

    TEST(count_generator_custom_type)
    {
        auto result = count<int32_t>(-2) | take_n(3);

        std::vector<int32_t> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::equals(-2, vec[0]);
        test::assert::equals(-1, vec[1]);
        test::assert::equals(0, vec[2]);
    }
};