#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(accumulate_test)
{
    TEST(accumulate_zero_items)
    {
        std::vector<int> in { };
        auto value = in | to_generator() | accumulate(-1, std::plus<> {});
        test::assert::equals(-1, value);
    }

    TEST(accumulate_one_item)
    {
        std::vector<int> in { 42 };
        auto value = in | to_generator() | accumulate(0, std::plus<> {});
        test::assert::equals(42, value);
    }

    TEST(accumualte_multiple_items)
    {
        auto value = count() | take_n(6) | accumulate(size_t { }, std::plus<> {});
        test::assert::equals(15, value);
    }
};