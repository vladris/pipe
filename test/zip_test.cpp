#include <iterator>

#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(zip_test)
{
    TEST(zip_zero_items)
    {
        std::vector<std::pair<int, int>> out { };
        std::vector<int> { } | to_generator() | zip_with(count<int>() | take_n(5)) | collect(std::back_inserter(out));

        test::assert::equals(0, out.size());
    }

    TEST(zip_with_shorter)
    {
        std::vector<std::pair<int, char>> out { };
        count(0) | take_n(5) | zip_with(std::vector<char> { 'a', 'b', 'c' }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::is_true(out[0].first == 0 && out[0].second == 'a');
        test::assert::is_true(out[1].first == 1 && out[1].second == 'b');
        test::assert::is_true(out[2].first == 2 && out[2].second == 'c');
    }

    TEST(zip_with_longer)
    {
        std::vector<std::pair<int, char>> out { };
        count<int>() | take_n(3) | zip_with(std::vector<char> { 'a', 'b', 'c', 'd', 'e' }) | collect(std::back_inserter(out));

        test::assert::equals(3, out.size());
        test::assert::is_true(out[0].first == 0 && out[0].second == 'a');
        test::assert::is_true(out[1].first == 1 && out[1].second == 'b');
        test::assert::is_true(out[2].first == 2 && out[2].second == 'c');
    }
};