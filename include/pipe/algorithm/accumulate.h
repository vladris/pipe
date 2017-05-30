#pragma once
#include <pipe/algorithm/algorithm.h>

namespace pipe { namespace algorithm {

template <typename Generator, typename T, typename BinaryOperation>
auto accumulate(Generator gen, const T& initial_value, BinaryOperation op)
{
	auto acc{ initial_value };

	for (auto&& item : gen)
		acc = op(acc, item);

	return acc;
}

template <typename T, typename BinaryOperation>
auto accumulate(T initial_value, BinaryOperation op)
{
	return details::algorithm([=](auto gen) { return accumulate(std::move(gen), initial_value, op); });
}

}} // namespace pipe::algorithm
