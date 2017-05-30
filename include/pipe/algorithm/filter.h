#pragma once

namespace pipe { namespace algorithm {


template <typename Generator, typename Predicate>
auto filter(Generator gen, Predicate pred) -> Generator
{
	for (auto&& item : gen)
		if (pred(item))
			co_yield item;
}


namespace details {

template <typename Predicate>
struct filter_t
{
    Predicate pred;

    template <typename Generator>
    auto operator()(Generator gen) -> Generator
    {
		return filter(std::move(gen), pred);
    }
};

} // namespace details

template <typename Predicate>
auto filter(Predicate pred)
{
    return details::filter_t<Predicate> { pred };
}

}} // namespace pipe::algorithm
