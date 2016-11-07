#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(for_each_test)
{
    TEST(for_each_multiple_items)
    {
        int sum = 0;
        count(1) | take_n(5) | for_each([&sum](auto& i) { sum += i; });

        test::assert::equals(15, sum);
    }
};