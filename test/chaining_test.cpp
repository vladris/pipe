#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(chaining_test)
{
    TEST(chaing_operations)
    {
        auto result = generate({ 1, 2, 3, 4, 5, 6 }) 
            | filter([](auto& i) { return i % 2 == 0; }) 
            | map([](auto& i) { return i * 2; }) 
            | accumulate(0, std::plus<> {});

        test::assert::equals(24, result);
    }
};