#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename OutputIterator>
struct collect_t
{
    OutputIterator it;

    template <typename Generator>
    static void apply(Generator gen, collect_t algorithm)
    {
        for (auto&& item : gen)
            *algorithm.it++ = item;
    }
};

} // namespace details

template <typename OutputIterator>
auto collect(OutputIterator it)
{
    return details::collect_t<OutputIterator> { it };
}

}} // namespace pipe::algorithm
