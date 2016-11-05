#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename Predicate>
struct filter_t
{
    Predicate pred;
};

template <typename T, typename Predicate>
auto operator|(generator_t<T>& gen, filter_t<Predicate>& filter)
{
    return ::filter(std::move(gen), filter.pred);
}

} // namespace details

template <typename T, typename Predicate>
auto filter(generator_t<T> gen, Predicate pred)
{
    for (auto&& item : gen)
        if (pred(item))
            co_yield item;
}

template <typename Predicate>
auto filter(Predicate pred)
{
    return details::filter_t<Predicate>{ pred };
}

}} // namespace pipe::algorithm
