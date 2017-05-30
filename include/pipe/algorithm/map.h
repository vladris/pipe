#pragma once
#include <type_traits>

namespace pipe { namespace algorithm {

template <template <typename, typename> typename Generator, typename T, typename Allocator, typename UnaryOperation>
auto map(Generator<T, Allocator> gen, UnaryOperation op) -> Generator<typename std::result_of<UnaryOperation(T&)>::type, Allocator>
{
	for (auto&& item : gen)
		co_yield op(item);
}

namespace details {

template <typename UnaryOperation>
struct map_t
{
    UnaryOperation op;

    template <typename Generator>
    auto operator()(Generator gen)
	{
		return map(std::move(gen), op);
    }
};

} // namespace details

template <typename UnaryOperation>
auto map(UnaryOperation op)
{
    return details::map_t<UnaryOperation> { op };
}

}} // namespace pipe::algorithm
