#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename UnaryOperation>
struct map_t
{
    UnaryOperation op;

    template <typename T>
    auto operator()(generator_t<T> gen)
    {
        for (auto&& item : gen)
            co_yield op(item);
    }
};

} // namespace details

template <typename UnaryOperation>
auto map(UnaryOperation op)
{
    return details::map_t<UnaryOperation> { op };
}

}} // namespace pipe::algorithm
