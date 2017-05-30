#pragma once
#include <pipe/algorithm/algorithm.h>
#include <pipe/algorithm/accumulate.h>

namespace pipe { namespace algorithm {

template <template <typename, typename> typename Generator, typename T, typename Allocator, typename BinaryOperation>
auto fold(Generator<T, Allocator> gen, BinaryOperation op) -> T
{
	auto it = gen.begin();

	if (it == gen.end())
		return {};

	return gen | accumulate(*it, op);
}

template <typename BinaryOperation>
auto fold(BinaryOperation op)
{
	return details::algorithm([=](auto gen) { return fold(std::move(gen), op); });
}

}} // namespace pipe::algorithm
