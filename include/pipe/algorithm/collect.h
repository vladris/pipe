#pragma once
#include <pipe/algorithm/algorithm.h>

namespace pipe { namespace algorithm {

template <typename Generator, typename OutputIterator>
void collect(Generator gen, OutputIterator it)
{
	for (auto&& item : gen)
		*it++ = item;
}

template <typename OutputIterator>
auto collect(OutputIterator it)
{
	return details::algorithm([=](auto gen) { return collect(std::move(gen), it); });
}

}} // namespace pipe::algorithm
