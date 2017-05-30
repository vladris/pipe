#pragma once
#include <pipe/algorithm/algorithm.h>

namespace pipe { namespace algorithm {

template <typename Generator, typename Predicate>
auto filter(Generator gen, Predicate pred) -> Generator
{
	for (auto&& item : gen)
		if (pred(item))
			co_yield item;
}

template <typename Predicate>
auto filter(Predicate pred)
{
	return details::algorithm([=](auto gen) { return filter(std::move(gen), pred); });
}

}} // namespace pipe::algorithm
