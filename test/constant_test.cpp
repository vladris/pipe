#include "pipe/functional.h"

#include "pintest.hpp"

using namespace pipe::functional;

TEST_GROUP(constant_test)
{
    TEST(constant_call)
    {
        auto c = constant(42);

        test::assert::equals(42, c());
        test::assert::equals(42, c());
        test::assert::equals(42, c());
    }
};