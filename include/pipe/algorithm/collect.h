#pragma once

namespace pipe { namespace algorithm {

template <typename Generator, typename OutputIterator>
void collect(Generator gen, OutputIterator it)
{
	for (auto&& item : gen)
		*it++ = item;
}

namespace details {

template <typename OutputIterator>
struct collect_t
{
    OutputIterator it;

    template <typename Generator>
    void operator()(Generator gen)
    {
		collect(std::move(gen), it);
    }
};

} // namespace details

template <typename OutputIterator>
auto collect(OutputIterator it)
{
    return details::collect_t<OutputIterator> { it };
}

}} // namespace pipe::algorithm
