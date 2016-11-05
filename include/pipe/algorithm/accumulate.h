#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename T, typename BinaryOperation>
struct accumulate_t
{
    const T initial_value;
    BinaryOperation op;
};

template <typename T, typename U, typename BinaryOperation>
auto operator|(generator_t<T>& gen, accumulate_t<U, BinaryOperation>& accumulate)
{
    return ::accumulate(std::move(gen), accumulate.initial_value, accumulate.op);
}

} // namespace details

template <typename T, typename U, typename BinaryOperation>
auto accumulate(generator_t<T> gen, U initial_value, BinaryOperation op)
{
    auto acc { initial_value };

    for (auto&& item : gen)
        acc = op(acc, item);

    return acc;
}

template <typename T, typename BinaryOperation>
auto accumulate(T initial_value, BinaryOperation op)
{
    return details::accumulate_t<T, BinaryOperation> { initial_value, op };
}

}} // namespace pipe::algorithm
