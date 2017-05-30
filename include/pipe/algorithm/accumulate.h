#pragma once

namespace pipe { namespace algorithm {

template <typename Generator, typename T, typename BinaryOperation>
auto accumulate(Generator gen, const T& initial_value, BinaryOperation op)
{
	auto acc{ initial_value };

	for (auto&& item : gen)
		acc = op(acc, item);

	return acc;
}

namespace details {

template <typename T, typename BinaryOperation>
struct accumulate_t
{
    const T initial_value;
    BinaryOperation op;

    template <typename Generator>
    auto operator()(Generator gen)
    {
        return accumulate(std::move(gen), initial_value, op);
    }
};

} // namespace details

template <typename T, typename BinaryOperation>
auto accumulate(T initial_value, BinaryOperation op)
{
    return details::accumulate_t<T, BinaryOperation> { initial_value, op };
}

}} // namespace pipe::algorithm
