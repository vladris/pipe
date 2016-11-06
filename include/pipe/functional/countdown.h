#pragma once

namespace pipe { namespace functional {

namespace details {

template <typename T>
struct countdown_t
{
    T n;

    template <typename ...Args>
    bool operator()(Args&& ...)
    {
        if (n == 0)
            return false;

        --n;
        return true;
    }
};

} // namespace details

template <typename T = size_t>
auto countdown(T initial_value)
{
    return details::countdown_t<T> { initial_value };
}

}} // namespace pipe::functional
