#pragma once

namespace pipe { namespace functional {

struct identity
{
    template <typename T>
    auto operator()(T&& arg)
    {
        return arg;
    }
};

}} // namespace pipe::functional
