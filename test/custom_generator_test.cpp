#include "pipe/algorithm.h"
#include "pipe/traits.h"

#include "pintest.hpp"
#include "utils.h"

using namespace pipe::algorithm;

// Implement a generator-compatible type
template <typename T, typename Allocator = std::allocator<char>>
struct custom_gen
{
    using promise_type = typename std::experimental::generator<T>::promise_type;

    custom_gen(promise_type& promise) : _gen(promise) { }
    custom_gen(custom_gen&& other) : _gen(std::move(other._gen)) { }
    custom_gen(const custom_gen<T>&) = delete;
    custom_gen &operator=(const custom_gen&) = delete;

    auto begin() { return _gen.begin(); }
    auto end() { return _gen.end(); }

    std::experimental::generator<T> _gen;
};

template <typename T>
struct pipe::is_generator<custom_gen<T>>
{
    static const bool value = true;
};

// Generator function using custom generator type
auto generate_custom(std::vector<int> vec) -> custom_gen<int>
{
    for (auto&& item : vec)
        co_yield item;
}

TEST_GROUP(custom_generator_test)
{
    TEST(using_custom_generator)
    {
        auto filtered = generate_custom({ 1, 2, 3, 4, 5, 6 }) 
            | filter([](auto& i) { return i % 2 == 0; });

        static_assert(std::is_same<custom_gen<int>, decltype(filtered)>::value, "Pipe should propagate custom generator type");

        auto mapped = filtered | map([](auto& i) -> char { return i; });

        static_assert(std::is_same<custom_gen<char>, decltype(mapped)>::value, "Pipe should propagate custom generator type");

        test::assert::equals(12, mapped | accumulate(0, std::plus<> {}));
    }
};