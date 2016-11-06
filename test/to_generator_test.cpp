#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(to_generator_test)
{
    TEST(to_generator_from_container)
    {
        std::vector<int> in = { 1, 2, 3, 4, 5 };
        auto result = to_generator(in) | length();
        test::assert::equals(5, result);
    }

    TEST(to_generator_from_iterators)
    {
        std::vector<int> in = { 1, 2, 3, 4, 5 };
        auto result = to_generator(in.begin(), in.end()) | length();
        test::assert::equals(5, result);
    }

    TEST(to_generator_with_pipe)
    {
        std::vector<int> in = { 1, 2, 3, 4, 5 };
        auto result = in | to_generator() | length();
        test::assert::equals(5, result);
    }
};