#pragma once
#include <pipe/functional.h>

namespace pipe { namespace algorithm {

namespace details {

template <typename Predicate>
struct all_t
{
    Predicate pred;

    template <typename Generator>
    auto operator()(Generator gen)
    {
        for (auto&& item : gen)
            if (!pred(item))
                return false;

        return true;
    }
};

template <typename Predicate>
struct some_t
{
    Predicate pred;

    template <typename Generator>
    auto operator()(Generator gen)
    {
        return !(gen | none(pred));
    }
};

} // namespace details

template <typename Predicate>
auto all(Predicate pred)
{
    return details::all_t<Predicate> { pred };
}

template <typename Predicate>
auto none(Predicate pred)
{
    return all(pipe::functional::negate(pred));
}

template <typename Predicate>
auto some(Predicate pred)
{
    return details::some_t<Predicate> { pred };
}

}} // namespace pipe::algorithm
