#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(fold_test)
{
    TEST(fold_zero_items)
    {
        auto value = generate({}) | fold(std::plus<> {});
        test::assert::equals(0, value);
    }

    TEST(fold_one_item)
    {
        auto value = generate({ 42 }) | fold(std::plus<> {});
        test::assert::equals(42, value);
    }

    TEST(fold_multiple_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | fold(std::plus<> {});
        test::assert::equals(15, value);
    }
};