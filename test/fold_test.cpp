#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::functional;
using namespace pipe::generator;

TEST_GROUP(fold_test)
{
    TEST(fold_zero_items)
    {
        auto value = repeat(constant(42)) | take_n(0) | fold(std::plus<> {});

        test::assert::equals(0, value);
    }

    TEST(fold_one_item)
    {
        auto value = repeat(constant(42)) | take_n(1) | fold(std::plus<> {});

        test::assert::equals(42, value);
    }

    TEST(fold_multiple_items)
    {
        auto value = count() | take_n(6) | fold(std::plus<> {});

        test::assert::equals(15, value);
    }
};