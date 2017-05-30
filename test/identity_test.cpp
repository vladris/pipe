#include "pipe/functional.h"

#include "pintest.hpp"

using namespace pipe::functional;

TEST_GROUP(identity_test)
{
    TEST(identity_predicate)
    {
		auto pred = identity();

        test::assert::equals(42, pred(42));
        test::assert::equals(0, pred(0));
    }
};