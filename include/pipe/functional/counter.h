#pragma once

namespace pipe { namespace functional {

template <typename T = size_t>
auto counter(T initial_value = T{})
{
	return [=](auto&& ...) mutable {
		return initial_value++;
	};
}

}} // namespace pipe::functional
