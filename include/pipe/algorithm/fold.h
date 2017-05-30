#pragma once
#include <pipe/algorithm/accumulate.h>

namespace pipe { namespace algorithm {

namespace details {

template <typename BinaryOperation>
struct fold_t
{
    BinaryOperation op;

    template <template <typename, typename> typename Generator, typename T, typename Allocator>
    auto operator()(Generator<T, Allocator> gen) -> T
    {
        auto it = gen.begin();

        if (it == gen.end())
            return {};

        return gen | accumulate(*it, op);
    }
};

} // namespace details

template <typename BinaryOperation>
auto fold(BinaryOperation op)
{
    return details::fold_t<BinaryOperation> { op };
}

}} // namespace pipe::algorithm
