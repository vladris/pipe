#pragma once

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
    return take_while([pred](auto& item) { return !pred(item); });
}

inline auto take_n(size_t n)
{
    return take_while([n](auto&) mutable { return n-- > 0; });
}

}} // namespace pipe::algorithm
