#pragma once
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

namespace details {

template <typename Predicate>
struct drop_while_t
{
    Predicate pred;

    template <typename Generator>
    auto operator()(Generator gen)
    {
		return drop_while(std::move(gen), pred);
    }
};

} // namespace details

template <typename Predicate>
auto drop_while(Predicate pred)
{
    return details::drop_while_t<Predicate> { pred };
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
