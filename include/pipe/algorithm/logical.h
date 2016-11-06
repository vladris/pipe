#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename Predicate>
struct all_t
{
    Predicate pred;

    template <typename Generator>
    static auto apply(Generator gen, all_t algorithm)
    {
        for (auto&& item : gen)
            if (!algorithm.pred(item))
                return false;

        return true;
    }
};

template <typename Predicate>
struct some_t
{
    Predicate pred;

    template <typename Generator>
    static auto apply(Generator gen, some_t algorithm)
    {
        return !(gen | none(algorithm.pred));
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
    return all([pred](auto& item) { return !pred(item); });
}

template <typename Predicate>
auto some(Predicate pred)
{
    return details::some_t<Predicate> { pred };
}

}} // namespace pipe::algorithm
