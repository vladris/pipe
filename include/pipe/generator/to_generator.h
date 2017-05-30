#pragma once
#include <experimental/generator>
#include <memory>

namespace pipe { namespace generator {

template <template <typename, typename> typename Generator = std::experimental::generator, typename Allocator = std::allocator<char>, typename Range>
auto to_generator(Range& range) -> Generator<typename Range::value_type, Allocator>
{
	for (auto&& item : range)
		co_yield item;
}

template <template <typename, typename> typename Generator = std::experimental::generator, typename Allocator = std::allocator<char>, typename InputIterator>
auto to_generator(InputIterator begin, InputIterator end) -> Generator<typename std::iterator_traits<InputIterator>::value_type, Allocator>
{
	for (auto it = begin; it != end; it++)
		co_yield *it;
}

namespace details {

template <template <typename, typename> typename Generator = std::experimental::generator, typename Allocator = std::allocator<char>>
struct to_generator_t
{
};

template <typename Range, template <typename, typename> typename Generator = std::experimental::generator, typename Allocator = std::allocator<char>>
auto operator|(Range& range, to_generator_t<Generator, Allocator>&&)
{
	return to_generator<Generator, Allocator>(range);
}

} // namespace details

template <template <typename, typename> typename Generator = std::experimental::generator, typename Allocator = std::allocator<char>>
auto to_generator()
{
    return details::to_generator_t<Generator, Allocator> { };
}

}} // namespace pipe::generator
