#pragma once

namespace pipe { namespace functional {

template <typename T = size_t>
auto countdown(T initial_value)
{
	return [=](auto&& ...) mutable {
		if (initial_value == 0)
			return false;

		--initial_value;
		return true;
	}; 
}

}} // namespace pipe::functional
