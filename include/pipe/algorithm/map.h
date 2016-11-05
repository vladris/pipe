#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename UnaryOperation>
struct map_t
{
    UnaryOperation op;
};

template <typename T, typename UnaryOperation>
auto operator|(generator_t<T>& gen, map_t<UnaryOperation>& map)
{
    return ::map(std::move(gen), map.op);
}

} // namespace details

template <typename T, typename UnaryOperation>
auto map(generator_t<T> gen, UnaryOperation op)
{
    for (auto&& item : gen)
        co_yield op(item);
}

template <typename UnaryOperation>
auto map(UnaryOperation op)
{
    return details::map_t<UnaryOperation> { op };
}

}} // namespace pipe::algorithm
