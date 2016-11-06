#include "pipe/algorithm.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

TEST_GROUP(zip_test)
{
    TEST(zip_zero_items)
    {
        auto result = generate({}) | zip_with(generate({ 1, 2, 3, 4, 5}));

        std::vector<std::pair<int, int>> vec(result.begin(), result.end());

        test::assert::equals(0, vec.size());
    }

    TEST(zip_with_shorter)
    {
        auto result = generate({ 1, 2, 3, 4, 5 }) | zip_with(generate<char>({ 'a', 'b', 'c' }));

        std::vector<std::pair<int, char>> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::is_true(vec[0].first == 1 && vec[0].second == 'a');
        test::assert::is_true(vec[1].first == 2 && vec[1].second == 'b');
        test::assert::is_true(vec[2].first == 3 && vec[2].second == 'c');
    }

    TEST(zip_with_longer)
    {
        auto result = generate({ 1, 2, 3 }) | zip_with(generate<char>({ 'a', 'b', 'c', 'd', 'e' }));

        std::vector<std::pair<int, char>> vec(result.begin(), result.end());

        test::assert::equals(3, vec.size());
        test::assert::is_true(vec[0].first == 1 && vec[0].second == 'a');
        test::assert::is_true(vec[1].first == 2 && vec[1].second == 'b');
        test::assert::is_true(vec[2].first == 3 && vec[2].second == 'c');
    }
};