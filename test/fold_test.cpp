#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(fold_test)
{
    TEST(fold_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | fold(std::plus<> {});
        test::assert::equals(0, value);
    }

    TEST(fold_one_item)
    {
        std::vector<int> in { 42 };
        auto value = in | to_generator() | fold(std::plus<> {});
        test::assert::equals(42, value);
    }

    TEST(fold_multiple_items)
    {
        auto value = count() | take_n(6) | fold(std::plus<> {});
        test::assert::equals(15, value);
    }
};