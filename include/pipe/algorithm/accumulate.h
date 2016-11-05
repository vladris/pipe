#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename U, typename BinaryOperation>
struct accumulate_t
{
    const U initial_value;
    BinaryOperation op;

    template <typename T>
    auto operator()(generator_t<T> gen)
    {
        auto acc { initial_value };

        for (auto&& item : gen)
            acc = op(acc, item);

        return acc;
    }
};

} // namespace details

template <typename T, typename BinaryOperation>
auto accumulate(T initial_value, BinaryOperation op)
{
    return details::accumulate_t<T, BinaryOperation> { initial_value, op };
}

}} // namespace pipe::algorithm
