#pragma once

namespace pipe { namespace functional {

template <typename Predicate>
auto negate(Predicate pred)
{
	return [=](auto&& ...args) { return !pred(std::forward<decltype(args)>(args)...); };
}

}} // namespace pipe::functional
