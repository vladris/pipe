#pragma once
#include <utility>

namespace pipe { namespace algorithm {

namespace details {

template <template <typename, typename> typename Generator, typename U, typename Allocator>
struct zip_with_t
{
    Generator<U, Allocator> gen;

    template <template <typename, typename> typename Generator, typename T, typename Allocator>
    static auto apply(Generator<T, Allocator> gen, zip_with_t algorithm) -> Generator<std::pair<T, U>, Allocator>
    {
        auto it1 = gen.begin();
        auto it2 = algorithm.gen.begin();
        for (; it1 != gen.end() && it2 != algorithm.gen.end(); ++it1, ++it2)
            co_yield std::make_pair(*it1, *it2);
    }
};

} // namespace details

template <template <typename, typename> typename Generator, typename T, typename Allocator>
auto zip_with(Generator<T, Allocator> gen)
{
    return details::zip_with_t<Generator, T, Allocator> { std::move(gen) };
}

}} // namespace pipe::algorithm
