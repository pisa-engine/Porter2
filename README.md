# Porter2
Porter2 stemming library

[![Build Status](https://travis-ci.org/pisa-engine/Porter2.svg?branch=master)](https://travis-ci.org/pisa-engine/Porter2)

## Usage

```cpp
#include <iostream>
#include "Porter2/Porter2.hpp"

int main(int argc, char **argv) {
    stem::Porter2 stemmer;
    auto thestem = stemmer.stem("eating");
    std::cout << thestem << std::endl; // eat
    return 0;
}
```
