![pipe](https://raw.githubusercontent.com/vladris/pipe/master/pipe.jpg)

Pipe is an experimental algorithm library for C++ generators. It leverages the "pipe" `operator|` to compose generator operations and create functional-style pipelines. For example, here is a sum of squares from 1 to 10 using **Pipe**:

```c++
auto sum_of_squares = count(1)            // start counting from 1
    | take_n(10)                          // take the first 10 yielded elements 
    | map([](auto& i) { return i * i; })  // square them
    | fold(std::plus<> { });              // fold them with std::plus
```

The library requires coroutines (see the [Coroutines Techincal Specification](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0057r4.pdf)) currently available in VS 2015 Update 3 with the `/await` compiler option.

# Getting Started

Pipe is a header only library. Get it from this repository:

```cmd
git clone https://github.com/vladris/pipe
```

Add the `include` directory to the compiler include path. Using VS 2015 Update 3, make sure to add the `/await` flag to the compiler to enable experimental coroutine support. Other compliers are not yet supported.

# Pipe library

The library has the following public headers:

* [algorithm.h](https://github.com/vladris/pipe/wiki/algorithm.h) providing algorithms that work on generators
* [functional.h](https://github.com/vladris/pipe/wiki/functional.h) providing a set of useful functors
* [generator.h](https://github.com/vladris/pipe/wiki/generator.h) providing functions to create generators
* [traits.h](https://github.com/vladris/pipe/wiki/traits.h) providing type traits used by the library
