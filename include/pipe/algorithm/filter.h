#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename Predicate>
struct filter_t
{
    Predicate pred;

    template <typename Generator>
    static auto apply(Generator gen, filter_t algorithm) -> Generator
    {
        for (auto&& item : gen)
            if (algorithm.pred(item))
                co_yield item;
    }
};

} // namespace details

template <typename Predicate>
auto filter(Predicate pred)
{
    return details::filter_t<Predicate> { pred };
}

}} // namespace pipe::algorithm
