#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename UnaryFunction>
struct for_each_t
{
    UnaryFunction func;

    template <typename Generator>
    void operator()(Generator gen)
    {
        for (auto&& item : gen)
            func(item);
    }
};

} // namespace details

template <typename UnaryFunction>
auto for_each(UnaryFunction func)
{
    return details::for_each_t<UnaryFunction> { func };
}

}} // namespace pipe::algorithm
