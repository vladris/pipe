#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;
using namespace pipe::functional;

TEST_GROUP(repeat_test)
{
    TEST(repeat_generator)
    {
        auto result = repeat(constant(1)) | take_n(3) | all([](auto& i) { return i == 1; });

        test::assert::is_true(result);
    }
};