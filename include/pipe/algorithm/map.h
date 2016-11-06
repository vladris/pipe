#pragma once
#include <type_traits>

namespace pipe { namespace algorithm {

namespace details {

template <typename UnaryOperation>
struct map_t
{
    UnaryOperation op;

    template <template <typename, typename> typename Generator, typename T, typename Allocator>
    static auto apply(Generator<T, Allocator> gen, map_t algorithm) -> Generator<typename std::result_of<UnaryOperation(T&)>::type, Allocator>
    {
        for (auto&& item : gen)
            co_yield algorithm.op(item);
    }
};

} // namespace details

template <typename UnaryOperation>
auto map(UnaryOperation op)
{
    return details::map_t<UnaryOperation> { op };
}

}} // namespace pipe::algorithm
