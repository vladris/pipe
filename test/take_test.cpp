#include "pipe/algorithm.h"
#include "pipe/generator.h"

#include "pintest.hpp"

using namespace pipe::algorithm;
using namespace pipe::generator;

TEST_GROUP(take_test)
{
    TEST(take_while_zero_items)
    {
        std::vector<int> in { };
        auto result = in | to_generator() | take_while([](auto&) { return true; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(take_while_no_items)
    {
        std::vector<int> in { 1, 2, 3 };
        auto result = in | to_generator() | take_while([](auto&) { return false; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(take_while_some_items)
    {
        std::vector<int> in { 1, 2, 3, 4, 5, 6 };
        auto result = in | to_generator() | take_while([](auto& item) { return item < 4; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(1, vec[0]);
        test::assert::equals(2, vec[1]);
        test::assert::equals(3, vec[2]);
    }

    TEST(take_while_all_items)
    {
        std::vector<int> in { 1, 2, 3, 4, 5, 6 };
        auto result = in | to_generator() | take_while([](auto& item) { return true; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(6, vec.size());
    }

    TEST(take_until_zero_items)
    {
        std::vector<int> in { };
        auto result = in | to_generator() | take_until([](auto&) { return false; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(take_until_no_items)
    {
        std::vector<int> in { 1, 2, 3 };
        auto result = in | to_generator() | take_until([](auto&) { return true; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(take_until_some_items)
    {
        std::vector<int> in { 1, 2, 3, 4, 5, 6 };
        auto result = in | to_generator() | take_until([](auto& item) { return item > 3; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(1, vec[0]);
        test::assert::equals(2, vec[1]);
        test::assert::equals(3, vec[2]);
    }

    TEST(take_until_all_items)
    {
        std::vector<int> in { 1, 2, 3, 4, 5, 6 };
        auto result = in | to_generator() | take_until([](auto& item) { return false; });
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(6, vec.size());
    }

    TEST(take_n_zero_items)
    {
        std::vector<int> in { };
        auto result = in | to_generator() | take_n(42);
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(0, vec.size());
    }

    TEST(take_n_some_items)
    {
        std::vector<int> in { 1, 2, 3, 4, 5, 6 };
        auto result = in | to_generator() | take_n(3);
        std::vector<int> vec(result.begin(), result.end());
        test::assert::equals(3, vec.size());
        test::assert::equals(1, vec[0]);
        test::assert::equals(2, vec[1]);
        test::assert::equals(3, vec[2]);
    }

    TEST(take_n_all_items)
    {
        std::vector<int> in { 1, 2, 3, 4, 5, 6 };
        auto result = in | to_generator() | take_n(42);
        std::vector<int> vec(result.begin(), result.end());        
        test::assert::equals(6, vec.size());
    }
};