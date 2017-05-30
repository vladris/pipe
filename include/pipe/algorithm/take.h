#pragma once
#include <pipe/functional.h>

namespace pipe { namespace algorithm {

template <typename Generator, typename Predicate>
auto take_while(Generator gen, Predicate pred) -> Generator
{
	for (auto&& item : gen)
		if (pred(item))
			co_yield item;
		else
			return;
}

namespace details {

template <typename Predicate>
struct take_while_t
{
    Predicate pred;

    template <typename Generator>
    auto operator()(Generator gen) -> Generator
    {
		return take_while(std::move(gen), pred);
    }
};

} // namespace details

template <typename Predicate>
auto take_while(Predicate pred)
{
    return details::take_while_t<Predicate> { pred };
}

template <typename Predicate>
auto take_until(Predicate pred)
{
    return take_while(pipe::functional::negate(pred));
}

inline auto take_n(size_t n)
{
    return take_while(pipe::functional::countdown(n));
}

}} // namespace pipe::algorithm
