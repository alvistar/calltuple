Call Tuple
----------

Call Tuple provide a function that enables calling a function using a tuple as argument,
which will be unpacked.

Example:

```C++
int add (int first, int second) {
    return first+second;
}

auto t = std::make_tuple (4,5);
auto res = call(add, t);
```

The code is based on answer of stackoverflow by Kerrek SB:
http://stackoverflow.com/a/10766422

Then modified to support return value.

This is library is available as a block on https://www.biicode.com
