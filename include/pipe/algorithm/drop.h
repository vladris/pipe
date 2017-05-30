#pragma once
#include <pipe/algorithm/algorithm.h>
#include <pipe/functional.h>

namespace pipe { namespace algorithm {

template <typename Generator, typename Predicate>
auto drop_while(Generator gen, Predicate pred) -> Generator
{
	bool drop = true;

	for (auto&& item : gen)
	{
		if (drop)
			if (drop = pred(item))
				continue;

		co_yield item;		
	}
}

template <typename Predicate>
auto drop_while(Predicate pred)
{
	return details::algorithm([=](auto gen) { return drop_while(std::move(gen), pred); });
}

template <typename Predicate>
auto drop_until(Predicate pred)
{
    return drop_while(pipe::functional::negate(pred));
}

inline auto drop_n(size_t n)
{
    return drop_while(pipe::functional::countdown(n));
}

}} // namespace pipe::algorithm
