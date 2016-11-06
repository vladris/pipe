#include "pipe/functional.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::functional;

TEST_GROUP(countdown_test)
{
    TEST(countdown_predicate)
    {
        auto c = countdown(3);

        test::assert::is_true(c());
        test::assert::is_true(c());
        test::assert::is_true(c());
        test::assert::is_false(c());
        test::assert::is_false(c());
    }

    TEST(countdown_predicate_with_arguments)
    {
        auto c = countdown(3);

        test::assert::is_true(c(1, 2));
        test::assert::is_true(c(1, 2));
        test::assert::is_true(c(1, 2));
        test::assert::is_false(c(1, 2));
        test::assert::is_false(c(1, 2));
    }
};