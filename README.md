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

---

## <a name="generator">generator.h</a>

Generators are declared in `namespace pipe::generator`. 

### count

```c++
template <typename T = size_t, 
          template <typename, typename> typename Generator = std::experimental::generator, 
          typename Allocator = std::allocator<char>>
auto count(T initial_value = T {}) -> Generator<T, Allocator>;
```

`count` provides an infinite counter over the given type `T` (default is `size_t`) starting from the given initial value (default is `T { }`). Subsequent values are produced by incrementing the counter. 

Example:

```c++
std::vector<int> out { }
count<int>(-5) | take_n(5) | collect(std::back_inserter(out)); // out will contain { -5, -4, -3, -2, -1 }
```

### repeat

```c++
template <template <typename, typename> typename Generator = std::experimental::generator,
          typename Allocator = std::allocator<char>, typename Func>
auto repeat(Func func) -> Generator<typename std::result_of<Func()>::type, Allocator>;
```

`repeat` infinitely calls the given function `func` and yields its return value.
Example:

```c++
std::vector<int> out { }
repeat(constant(42)) | take_n(5) | collect(std::back_inserter(out)); // out will contain { 42, 42, 42, 42, 42 }
```

### to_generator

```c++
template <template <typename, typename> typename Generator = std::experimental::generator, 
          typename Allocator = std::allocator<char>, typename InputIterator>
auto to_generator(InputIterator begin, InputIterator end) -> Generator<typename std::iterator_traits<InputIterator>::value_type, Allocator>;

template <template <typename, typename> typename Generator = std::experimental::generator,
          typename Allocator = std::allocator<char>, typename Range>
auto to_generator(Range& range) -> Generator<typename Range::value_type, Allocator>;

template <template <typename, typename> typename Generator = std::experimental::generator,
          typename Allocator = std::allocator<char>>
auto to_generator();
```

The `to_generator` family of functions create generators from input ranges. 

The first version takes a `begin` and an `end` input iterators and yields each element.
The second version takes a `Range` type on which it expects `begin()` and `end()` methods returning iterators and a declared `Range::value_type`. It iterates over the range and yields each element.
The third version returns an internal type which can be used on the right hand side of `operator|` applied to a range, for example:

```c++
std::vector<int> in { 1, 2, 3 };
auto gen = in | to_generator(); // `gen` is a generator over `in` and yields its values
```
---

## <a name="functional">functional.h</a>

TBA

---

## <a name="algorithm">algorithm.h</a>

TBA

---

## <a name="traits">traits.h</a>

TBA

---

## <a name="customgenerators">Using custom generators</a>

TBA

---

