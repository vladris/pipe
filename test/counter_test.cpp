#include "pipe/functional.h"

#include "pintest.hpp"

using namespace pipe::functional;

TEST_GROUP(counter_test)
{
    TEST(counter_call)
    {
        auto c = counter();

        test::assert::equals(0, c());
        test::assert::equals(1, c());
        test::assert::equals(2, c());
        test::assert::equals(3, c());
    }

    TEST(counter_with_initial_value)
    {
        auto c = counter<int32_t>(-2);

        test::assert::equals(-2, c());
        test::assert::equals(-1, c());
        test::assert::equals(0, c());
        test::assert::equals(1, c());
    }
};