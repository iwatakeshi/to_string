# to_string
A `to_string()` helper for c++

## Usage

To use this library, install [buckaroo](https://github.com/LoopPerfect/buckaroo/wiki/Installation#buckaroo) and [buck](https://github.com/LoopPerfect/buckaroo/wiki/Installation#buck). Once installed, [initialize](https://github.com/LoopPerfect/buckaroo/wiki/Commands#init) buckaroo in your project folder and run the following command:

```bash
# Add the latest version
buckaroo add github.com/iwatakeshi/to_string/
```
You can also add a [version constraint](https://github.com/LoopPerfect/buckaroo/wiki/Version-Constraints-DSL) if you need to.

## Example

```cpp
#include "to_string.hpp"
#include <iostream>

int main() {
   
   std::cout << utils::to_string(true) << std::endl; // => true
   std::cout << utils::to_string('a') << std::endl; // => a
  
  return 0;
}
```
