#pragma once
#include <type_traits>
#include <pipe/algorithm/algorithm.h>

namespace pipe { namespace algorithm {

template <template <typename, typename> typename Generator, typename T, typename Allocator, typename UnaryOperation>
auto map(Generator<T, Allocator> gen, UnaryOperation op) -> Generator<typename std::result_of<UnaryOperation(T&)>::type, Allocator>
{
	for (auto&& item : gen)
		co_yield op(item);
}

template <typename UnaryOperation>
auto map(UnaryOperation op)
{
	return details::algorithm([=](auto gen) { return map(std::move(gen), op); });
}

}} // namespace pipe::algorithm
