#include "pipe/functional.h"

#include "pintest.hpp"

using namespace pipe::functional;

TEST_GROUP(negate_test)
{
    TEST(negate_predicate)
    {
        test::assert::is_false(negate([]() { return true; })());
        test::assert::is_true(negate([]() { return false; })());
    }

    TEST(negate_predicate_with_arguments)
    {
        test::assert::is_false(negate([](int a, int b) { return a + b == 42; })(21, 21));
        test::assert::is_true(negate([](int a, int b) { return a + b != 42; })(21, 21));
    }
};