#include "pipe/algorithm.h"
#include "pipe/functional.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::functional;
using namespace pipe::generator;

TEST_GROUP(drop_test)
{
    TEST(drop_while_zero_items)
    {
        std::vector<int> in { };
        auto result = in | to_generator() | drop_while(constant(true));
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(drop_while_no_items)
    {
        auto result = count<int>() | take_n(6) | drop_while(constant(false));
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(6, vec.size());
    }

    TEST(drop_while_some_items)
    {
        auto result = count<int>() | take_n(6) | drop_while([](auto& item) { return item < 3; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(3, vec[0]);
        test::assert::equals(4, vec[1]);
        test::assert::equals(5, vec[2]);
    }

    TEST(drop_while_all_items)
    {
        auto result = count<int>() | take_n(6) | drop_while(constant(true));
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(drop_until_zero_items)
    {
        auto result = std::vector<int> {} | to_generator() | drop_until(constant(true));
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(drop_until_no_items)
    {
        auto result = count<int>() | take_n(6) | drop_until(constant(true));
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(6, vec.size());
    }

    TEST(drop_until_some_items)
    {
        auto result = count<int>() | take_n(6) | drop_until([](auto& item) { return item > 2; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(3, vec[0]);
        test::assert::equals(4, vec[1]);
        test::assert::equals(5, vec[2]);
    }

    TEST(drop_until_all_items)
    {
        auto result = count<int>() | take_n(6) | drop_until(constant(false));
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(drop_n_zero_items)
    {
        std::vector<int> in { };
        auto result = in | to_generator() | drop_n(42);
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(drop_n_some_items)
    {
        auto result = count<int>() | take_n(6) | drop_n(3);
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(3, vec[0]);
        test::assert::equals(4, vec[1]);
        test::assert::equals(5, vec[2]);
    }

    TEST(drop_n_all_items)
    {
        auto result = count<int>() | take_n(6) | drop_n(42);
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }
};