#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(chaining_test)
{
    TEST(chaing_operations)
    {
        auto result = count()
            | take_n(7) 
            | filter([](auto& i) { return i % 2 == 0; }) 
            | map([](auto& i) { return i * 2; }) 
            | accumulate(size_t { }, std::plus<> {});

        test::assert::equals(24, result);
    }
};