#pragma once

namespace pipe { namespace functional {

namespace details {

template <typename T>
struct counter_t
{
    T n;

    template <typename ...Args>
    auto operator()(Args&& ...)
    {
        return n++;
    }
};

} // details

template <typename T = size_t>
auto counter(T initial_value = T {})
{
    return details::counter_t<T> { initial_value };
}

}} // namespace pipe::functional
