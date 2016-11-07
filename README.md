![pipe](https://raw.githubusercontent.com/vladris/pipe/master/pipe.jpg)

Pipe is an experimental algorithm library for C++ generators. It leverages the "pipe" `operator|` to compose generator operations and create functional-style pipelines. For example, here is a sum of squares from 1 to 10 using **Pipe**:

```c++
auto sum_of_squares = count(1) | take_n(10) | map([](auto& i) { return i * i; }) | fold(std::plus<> { });
```

The library requires coroutines (see the [Coroutines Techincal Specification](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0057r4.pdf)) currently available in VS 2015 Update 3 with the `/await` compiler option.

# Getting Started

Pipe is a header only library. Get it from this repository:

```cmd
git clone https://github.com/vladris/pipe
```

Add the `include` directory to the compiler include path. Using VS 2015 Update 3, make sure to add the `/await` flag to the compiler to enable experimental coroutine support. Other compliers are not yet supported.

# Pipe library

The library provides the following headers:

* [generator.h](#generator) providing functions to create generators
* [functional.h](#functional) providing a set of useful functors
* [algorithm.h](#algorithm) providing algorithms that work on generators
* [traits.h](#traits) providing type traits used by the library - see [using custom generators](#customgenerators)

## <a name="generator">generator.h</a>

TBA

## <a name="functional">functional.h</a>

TBA

## <a name="algorithm">algorithm.h</a>

TBA

## <a name="tratis">traits.h</a>

TBA

## <a name="customgenerators">Using custom generators</a>

TBA
