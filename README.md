# Data-Structures

A collection of C++ implementations of fundamental data structures and algorithms for coursework and educational purposes.

## Table of Contents

- [Introduction](#introduction)
- [Implemented Data Structures](#implemented-data-structures)
- [Algorithms](#algorithms)
- [Prerequisites](#prerequisites)
- [Building the Project](#building-the-project)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This repository contains hand-crafted implementations of key data structures in C++, aimed at deepening understanding of their internal workings. Each implementation follows best practices for modularity, memory management, and performance.

## Implemented Data Structures

- **Vector**: Dynamic array supporting random access, resizing, and iterators.
- **Linked List**: Singly and doubly linked lists with insert, delete, and traversal operations.
- **Stack**: LIFO container built on top of linked list.
- **Queue**: FIFO container built on top of linked list.
- **Set**: Unordered set implemented via hash table.
- **Tree**: Basic binary search tree with insert, search, and traversal.
- **Graph**: Adjacency list representation and BFS/DFS algorithms.

## Algorithms

- **Huffman Coding**: Construction of optimal prefix codes for data compression.
- **Traversal**: In-order, pre-order, post-order for trees; BFS and DFS for graphs.
- **Sorting Utilities**: Helper functions for sorting data when needed.

## Prerequisites

- C++ compiler with C++11 support or above (e.g., GCC, Clang, MSVC)
- CMake (version >= 3.5)
- Make (optional)

## Building the Project

```bash
git clone https://github.com/BenjaminDanker/Data-Structures.git
cd Data-Structures
mkdir build && cd build
cmake ..
make
```

## Usage

After building, executables for each module will be located in the `build/bin` directory. Run them directly:

```bash
./bin/vector_demo
./bin/linked_list_demo
# ...
```

## Examples

Sample usage of the vector implementation:

```cpp
#include "vector.hpp"

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}
```

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests. Please adhere to the existing code style and include tests for new features.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
