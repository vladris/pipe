#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::generator;
using namespace pipe::algorithm;

TEST_GROUP(repeat_test)
{
    TEST(repeat_generator)
    {
        auto result = repeat([](){ return 1; }) | take_n(3) | all([](auto& i) { return i == 1; });
        test::assert::is_true(result);
    }
};