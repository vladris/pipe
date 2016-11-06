#pragma once

namespace pipe { namespace functional {

namespace details {

template <typename Predicate>
struct negate_t
{
    Predicate pred;

    template <typename ...Args>
    bool operator()(Args&& ...args)
    {
        return !pred(std::forward<Args>(args)...);
    }
};

} // namespace details

template <typename Predicate>
auto negate(Predicate pred)
{
    return details::negate_t<Predicate> { pred };
}

}} // namespace pipe::functional
