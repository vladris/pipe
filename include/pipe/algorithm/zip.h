#pragma once
#include <utility>

namespace pipe { namespace algorithm {

namespace details {

template <template <typename, typename> typename Generator, typename U, typename Allocator>
struct zip_with_t
{
    Generator<U, Allocator> gen1;

    template <template <typename, typename> typename Generator, typename T, typename Allocator>
    auto operator()(Generator<T, Allocator> gen2) -> Generator<std::pair<T, U>, Allocator>
    {
        auto it1 = gen2.begin();
        auto it2 = gen1.begin();
        for (; it1 != gen2.end() && it2 != gen1.end(); ++it1, ++it2)
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
