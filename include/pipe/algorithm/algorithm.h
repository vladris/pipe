#pragma once
#include <utility>

namespace pipe { namespace algorithm { namespace details {

// Algorithm wrapper so we can wrap lambdas in a details namespace type to enable opreator| on them
template <typename Algorithm>
struct algorithm_t
{
	Algorithm algorithm;

	template <typename Generator>
	auto operator()(Generator gen)
	{
		return algorithm(std::move(gen));
	}
};

template <typename Algorithm>
auto algorithm(Algorithm&& algorithm)
{
	return algorithm_t<Algorithm> { std::move(algorithm) };
}

}}} // namespace pipe::algorithm::details