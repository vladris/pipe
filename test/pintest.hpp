// Pin test
//
// Copyright (c) 2016 Vlad Riscutia
// MIT License

#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

namespace test {
namespace details {

struct assert_failed_exception
{
    const std::string message;
};

enum class result : uint8_t
{
    Success = 0, // Test succeeded
    Failed,      // Assertion failed
    Exception,   // Test threw an exception
    Invalid      // Invalid test
};

struct test_registry
{
    using test_func = std::function<void()>;

    struct test
    {
        const std::string group;
        const std::string name;
        test_func func;
    };

    static auto use() -> test_registry&
    {
        static test_registry instance;

        return instance;
    }

    void push_group(const std::string& name)
    {
        _group = name;
    }

    void add_test(const std::string& name, test_func func)
    {
        _tests.push_back({ _group, name, func });
    }

    auto list_tests() -> const std::string&
    {
        static auto tests = get_tests();

    return tests;
    }

        auto find_test(const std::string& group, const std::string& name) -> std::vector<test>::iterator
    {
        return std::find_if(_tests.begin(), _tests.end(),
            [&](const test& t)
        {
            return t.group == group && t.name == name;
        });
    }

    auto end() -> std::vector<test>::iterator
    {
        return _tests.end();
    }

private:
    auto get_tests() -> std::string
    {
        auto result = std::accumulate(_tests.begin(), _tests.end(), std::string {},
            [](std::string& list, const test& t)
        {
            return list += t.group + "::" + t.name + ",";
        });

        return result.size() > 0 ? result.erase(result.size() - 1) : result;
    }

    std::string _group;
    std::vector<test> _tests;
};

struct test_executor
{
    static auto use() -> test_executor&
    {
        static test_executor instance;

        return instance;
    }

    auto run_test(const std::string& group, const std::string& name) -> result
    {
        return run_fixture(group, name);
    }

private:
    auto run_function(const std::string& group, const std::string& name) -> result
    {
        auto registry = test_registry::use();

        // Find function in fixture
        auto it = registry.find_test(group, name);

        // Invalid if not found
        if (it == registry.end())
            return result::Invalid;

        try
        {
            // Execute
            it->func();
        }
        catch (const assert_failed_exception& e)
        {
            std::cerr << group << "::" << name << ": " << e.message << std::endl;

            // Assertion failure
            return result::Failed;
        }
        catch (...)
        {
            std::cerr << group << "::" << name << ": unhandled exception" << std::endl;

            // Unhandled exception
            return result::Exception;
        }

        // Great success
        return result::Success;
    }

    auto run_fixture(const std::string& group, const std::string& test) -> result
    {
        // Don't run if exception in test setup
        if (run_function(group, "__setup") == result::Exception)
            return result::Exception;

        auto test_result = run_function(group, test);

        // Result becomes exception if exception in teardown
        if (run_function(group, "__teardown") == result::Exception)
            return result::Exception;

        return test_result;
    }
};

// Helper for instantiating and registering a test group
template <typename T> struct instance_helper
{
    std::unique_ptr<T> instance;

    instance_helper(const std::string& name)
    {
        // Register name-type pair
        test_registry::use().push_group(name);

        // Instantiate test group
        instance = std::unique_ptr<T>(new T {});
    }
};

// Helper for registering a test method
struct register_test_helper
{
    register_test_helper(const std::string& name, test_registry::test_func func)
    {
        // Register test and associate with group
        test_registry::use().add_test(name, func);
    }
};

#ifdef _MSC_VER
// inline allows implementation in header, __declspec(noinline) prevents actual inlining
#define WEAK    inline __declspec(noinline) __declspec(dllexport)
#else
#define WEAK    __attribute__((weak))
#endif // _MSC_VER

// List all tests
extern "C" WEAK const char *list_tests()
{
    return test_registry::use().list_tests().c_str();
}

// Runs the given test from the given group
extern "C" WEAK int run_test(const char *group, const char *name)
{
    return static_cast<int>(test_executor::use().run_test(group, name));
}

} // namespace details

  // Asserts
namespace assert {
inline void fail(const std::string& message = "")
{
    throw test::details::assert_failed_exception { message.empty() ? "called assert::fail" : message };
}

template <typename T, typename U>
inline void equals(const T& expected, const U& actual, const std::string& message = "")
{
    if (expected != actual)
        fail(message.empty() ? "assert::equals failed" : message);
}

template <typename T, typename U>
inline void not_equals(const T& expected, const U& actual, const std::string& message = "")
{
    if (expected == actual)
        fail(message.empty() ? "assert::not_equals failed" : message);
}

template <typename T>
inline void is_true(const T& actual, const std::string& message = "")
{
    if (!actual)
        fail(message.empty() ? "assert::is_true failed" : message);
}

template <typename T>
inline void is_false(const T& actual, const std::string& message = "")
{
    if (actual)
        fail(message.empty() ? "assert::is_false failed" : message);
}

template <typename T>
inline void is_null(const T& actual, const std::string& message = "")
{
    if (actual != nullptr)
        fail(message.empty() ? "assert::is_null failed" : message);
}

template <typename T>
inline void is_not_null(const T& actual, const std::string& message = "")
{
    if (actual == nullptr)
        fail(message.empty() ? "assert::is_not_null failed" : message);
}

template <typename T, typename Callable>
inline void throws(Callable c, const std::string& message = "")
{
    try
    {
        c();
    }
    catch (const T&)
    {
        return;
    }
    catch (...)
    {
        fail(message.empty() ? "assert::throws unexpected exception type" : message);
    }

    fail(message.empty() ? "assert::throws doesn't throw" : message);
}
} // namespace assert
} // namespace test

  // Test groups are classes
#define TEST_GROUP(name)    struct name; \
                            test::details::instance_helper<name> _ ## name ## _ ## instance(# name); \
                            struct name

  // Test (automatically registers itself)
#define TEST(name)          test::details::register_test_helper _ ## name { # name, [&]() { this->name(); } }; \
                            void name()

  // Setup and teardown
#define SETUP()        TEST(__setup)
#define TEARDOWN()     TEST(__teardown)