#pragma once

namespace pipe { namespace functional {

template <typename T>
auto constant(T value)
{
	return [=](auto&& ...) { return value; };
}

}} // namespace pipe::functional
