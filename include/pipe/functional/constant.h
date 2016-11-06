#pragma once

namespace pipe { namespace functional {

namespace details {

template <typename T>
struct constant_t
{
    const T value;

    template <typename ...Args>
    T operator()(Args&& ...args)
    {
        return value;
    }
};

} // namespace details

template <typename T>
auto constant(T value)
{
    return details::constant_t<T> { value };
}

}} // namespace pipe::functional
