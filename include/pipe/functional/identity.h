#pragma once

namespace pipe { namespace functional {

inline auto identity()
{
	return [](auto&& arg) { return arg; };
};

}} // namespace pipe::functional
