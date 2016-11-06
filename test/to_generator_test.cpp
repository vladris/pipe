#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(to_generator_test)
{
    TEST(to_generator_from_container)
    {
        std::vector<int> vec = { 1, 2, 3, 4, 5 };

        auto result = to_generator(vec) | length();

        test::assert::equals(5, result);
    }

    TEST(to_generator_from_iterators)
    {
        std::vector<int> vec = { 1, 2, 3, 4, 5 };

        auto result = to_generator(vec.begin(), vec.end()) | length();

        test::assert::equals(5, result);
    }

    TEST(to_generator_with_pipe)
    {
        std::vector<int> vec = { 1, 2, 3, 4, 5 };

        auto result = vec | to_generator() | length();

        test::assert::equals(5, result);
    }
};