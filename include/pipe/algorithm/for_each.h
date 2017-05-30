#pragma once

namespace pipe { namespace algorithm {

template <typename Generator, typename UnaryFunction>
void for_each(Generator gen, UnaryFunction func)
{
	for (auto&& item : gen)
		func(item);
}

namespace details {

template <typename UnaryFunction>
struct for_each_t
{
    UnaryFunction func;

    template <typename Generator>
    void operator()(Generator gen)
    {
		for_each(std::move(gen), func);
    }
};

} // namespace details

template <typename UnaryFunction>
auto for_each(UnaryFunction func)
{
    return details::for_each_t<UnaryFunction> { func };
}

}} // namespace pipe::algorithm
