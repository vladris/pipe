#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(zip_test)
{
    TEST(zip_zero_items)
    {
        std::vector<int> in { };
        auto result = in | to_generator() | zip_with(count<int>() | take_n(5));
        std::vector<std::pair<int, int>> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(zip_with_shorter)
    {
        auto result = count(0) | take_n(5) | zip_with(std::vector<char> { 'a', 'b', 'c' });
        std::vector<std::pair<int, char>> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::is_true(vec[0].first == 0 && vec[0].second == 'a');
        test::assert::is_true(vec[1].first == 1 && vec[1].second == 'b');
        test::assert::is_true(vec[2].first == 2 && vec[2].second == 'c');
    }

    TEST(zip_with_longer)
    {
        auto result = count<int>() | take_n(3) | zip_with(std::vector<char> { 'a', 'b', 'c', 'd', 'e' });
        std::vector<std::pair<int, char>> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::is_true(vec[0].first == 0 && vec[0].second == 'a');
        test::assert::is_true(vec[1].first == 1 && vec[1].second == 'b');
        test::assert::is_true(vec[2].first == 2 && vec[2].second == 'c');
    }
};