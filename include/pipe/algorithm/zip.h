#pragma once
#include <utility>

namespace pipe { namespace algorithm {

template <template <typename, typename> typename Generator, typename T, typename Allocator, template <typename, typename> typename Generator2, typename U, typename Allocator2>
auto zip(Generator<T, Allocator> gen1, Generator2<U, Allocator2> gen2) -> Generator<std::pair<T, U>, Allocator>
{
	auto it1 = gen1.begin();
	auto it2 = gen2.begin();
	for (; it1 != gen1.end() && it2 != gen2.end(); ++it1, ++it2)
		co_yield std::make_pair(*it1, *it2);
}

namespace details {

template <typename Generator>
struct zip_with_t
{
	Generator gen1;

	template <typename Generator>
	auto operator()(Generator gen2)
	{
		return zip(std::move(gen2), std::move(gen1));
	}
};

} // namespace details

template <typename Generator>
auto zip_with(Generator gen)
{
    return details::zip_with_t<Generator> { std::move(gen) };
}

}} // namespace pipe::algorithm
