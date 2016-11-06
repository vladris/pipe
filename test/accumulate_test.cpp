#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(accumulate_test)
{
    TEST(accumulate_zero_items)
    {
        auto value = generate({ }) | accumulate(-1, std::plus<> {});
        test::assert::equals(-1, value);
    }

    TEST(accumulate_one_item)
    {
        auto value = generate({ 42 }) | accumulate(0, std::plus<> {});
        test::assert::equals(42, value);
    }

    TEST(accumualte_multiple_items)
    {
        auto value = generate({ 1, 2, 3, 4, 5 }) | accumulate(0, std::plus<> {});
        test::assert::equals(15, value);
    }
};