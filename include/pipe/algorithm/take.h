#pragma once
#include <pipe/functional.h>

namespace pipe { namespace algorithm {

namespace details {

template <typename Predicate>
struct take_while_t
{
    Predicate pred;

    template <typename Generator>
    static auto apply(Generator gen, take_while_t algorithm) -> Generator
    {
        for (auto&& item : gen)
            if (algorithm.pred(item))
                co_yield item;
            else
                return;
    }
};

} // namespace details

template <typename Predicate>
auto take_while(Predicate pred)
{
    return details::take_while_t<Predicate> { pred };
}

template <typename Predicate>
auto take_until(Predicate pred)
{
    return take_while(pipe::functional::negate(pred));
}

inline auto take_n(size_t n)
{
    return take_while(pipe::functional::countdown(n));
}

}} // namespace pipe::algorithm
