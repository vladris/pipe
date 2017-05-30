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

template <typename Generator>
auto zip_with(Generator gen)
{
	return[gen2 = std::move(gen)](auto gen1) mutable { return zip(std::move(gen1), std::move(gen2)); };
}

}} // namespace pipe::algorithm
