#pragma once
#include <pipe/functional.h>

namespace pipe { namespace algorithm {

template <typename Generator, typename Predicate>
auto all(Generator gen, Predicate pred)
{
	for (auto&& item : gen)
		if (!pred(item))
			return false;

	return true;
}

template <typename Predicate>
auto all(Predicate pred)
{
	return [=](auto gen) { return all(std::move(gen), pred); };
}

template <typename Predicate>
auto none(Predicate pred)
{
    return all(pipe::functional::negate(pred));
}

template <typename Predicate>
auto some(Predicate pred)
{
	return pipe::functional::negate(none(pred));
}

}} // namespace pipe::algorithm
