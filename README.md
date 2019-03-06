# to_string
A `to_string()` helper for c++

This library is based on this [article](https://www.fluentcpp.com/2017/06/06/using-tostring-custom-types-cpp/).

## Usage

To use this library, install [buckaroo](https://github.com/LoopPerfect/buckaroo/wiki/Installation#buckaroo) and [buck](https://github.com/LoopPerfect/buckaroo/wiki/Installation#buck). Once installed, [initialize](https://github.com/LoopPerfect/buckaroo/wiki/Commands#init) buckaroo in your project folder and run the following command:

```bash
# Add the latest version
buckaroo add github.com/iwatakeshi/to_string/
```
You can also add a [version constraint](https://github.com/LoopPerfect/buckaroo/wiki/Version-Constraints-DSL) if you need to.

## Example

```cpp
#include <to_string.hpp>
#include <iostream>
#include <ostream>
using namespace stdlib;

// Override the '<<' operator
struct example {
  example() {};
  friend std::ostream operator << (std::ostream& os, const example& other) {
    os << "example" << std::endl;
    return os;
  }
};

// or define a to_string in std
std::string std::to_string(const example&) {
  return "example";
}

int main() {
   std::cout << to_string(1) << std::endl => 1
   std::cout << to_string(true) << std::endl; // => true
   std::cout << to_string('a') << std::endl; // => a
   std::cout << to_string("hello world") << std::endl; // => hello world
   std::cout << to_string(std::string("hello world")) << std::endl; // => hello world
   std::cout << to_string(example()) << std::endl; // => example
  return 0;
}
```
