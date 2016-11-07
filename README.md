![pipe](https://raw.githubusercontent.com/vladris/pipe/master/pipe.jpg)

Pipe is an experimental algorithm library for C++ generators. It leverages the "pipe" `operator|` to compose generator operations and create functional-style pipelines. For example, here is a sum of squares from 1 to 10 using Pipe:

```c++
auto sum_of_squares = count(1)            // start counting from 1
    | take_n(10)                          // take the first 10 yielded elements 
    | map([](auto& i) { return i * i; })  // square them
    | fold(std::plus<> { });              // fold them with std::plus
```

The library requires coroutines (see the [Coroutines Techincal Specification](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0057r4.pdf)) currently available in VS 2015 Update 3 with the `/await` compiler option.

See [this blog post](http://vladris.com/blog/2016/10/09/composable-generators.html) for ways to compose generators and the reason pipes are the way to go. 

# Getting Started

Pipe is a header only library. Get it from this repository:

```cmd
git clone https://github.com/vladris/pipe
```

Add the `include` directory to the compiler include path. Using VS 2015 Update 3, make sure to add the `/await` flag to the compiler to enable experimental coroutine support. Other compilers are not yet supported.

# Pipe library

The library has the following public headers:

* [algorithm.h](https://github.com/vladris/pipe/wiki/algorithm.h) providing algorithms that work on generators:
    * [accumulate](https://github.com/vladris/pipe/wiki/accumulate)
    * [all](https://github.com/vladris/pipe/wiki/all)
    * [collect](https://github.com/vladris/pipe/wiki/collect)
    * [drop_n](https://github.com/vladris/pipe/wiki/drop_n)
    * [drop_until](https://github.com/vladris/pipe/wiki/drop_until)
    * [drop_while](https://github.com/vladris/pipe/wiki/drop_while)
    * [filter](https://github.com/vladris/pipe/wiki/filter)
    * [for_each](https://github.com/vladris/pipe/wiki/for_each)
    * [fold](https://github.com/vladris/pipe/wiki/fold)
    * [length](https://github.com/vladris/pipe/wiki/length)
    * [map](https://github.com/vladris/pipe/wiki/map)
    * [max](https://github.com/vladris/pipe/wiki/max)
    * [min](https://github.com/vladris/pipe/wiki/min)
    * [none](https://github.com/vladris/pipe/wiki/none)
    * [some](https://github.com/vladris/pipe/wiki/some)
    * [take_n](https://github.com/vladris/pipe/wiki/take_n)
    * [take_until](https://github.com/vladris/pipe/wiki/take_until)
    * [take_while](https://github.com/vladris/pipe/wiki/take_while)
    * [zip_with](https://github.com/vladris/pipe/wiki/zip_with)
* [functional.h](https://github.com/vladris/pipe/wiki/functional.h) providing a set of useful functors:
    * [constant](https://github.com/vladris/pipe/wiki/constant)
    * [countdown](https://github.com/vladris/pipe/wiki/countdown)
    * [counter](https://github.com/vladris/pipe/wiki/counter)
    * [identity](https://github.com/vladris/pipe/wiki/identity)
    * [negate](https://github.com/vladris/pipe/wiki/negate)
* [generator.h](https://github.com/vladris/pipe/wiki/generator.h) providing functions to create generators:
    * [count](https://github.com/vladris/pipe/wiki/count)
    * [repeat](https://github.com/vladris/pipe/wiki/repeat)
    * [to_generator](https://github.com/vladris/pipe/wiki/to_generator)
* [traits.h](https://github.com/vladris/pipe/wiki/traits.h) providing type traits used by the library:
    * [is_generator](https://github.com/vladris/pipe/wiki/is_generator)
