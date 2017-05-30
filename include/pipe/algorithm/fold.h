#pragma once
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

namespace details {

template <typename BinaryOperation>
struct fold_t
{
    BinaryOperation op;

    template <typename Generator>
    auto operator()(Generator gen)
    {
		return fold(std::move(gen), op);
    }
};

} // namespace details

template <typename BinaryOperation>
auto fold(BinaryOperation op)
{
    return details::fold_t<BinaryOperation> { op };
}

}} // namespace pipe::algorithm
