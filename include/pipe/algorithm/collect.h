#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename OutputIterator>
struct collect_t
{
    OutputIterator it;

    template <typename Generator>
    void operator()(Generator gen)
    {
        for (auto&& item : gen)
            *it++ = item;
    }
};

} // namespace details

template <typename OutputIterator>
auto collect(OutputIterator it)
{
    return details::collect_t<OutputIterator> { it };
}

}} // namespace pipe::algorithm
