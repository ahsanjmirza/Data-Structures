# Data Structures Library

A collection of generic, header-only C++ implementations of fundamental data structures for educational and practical use.

## Table of Contents

* [Overview](#overview)
* [Implemented Data Structures](#implemented-data-structures)
* [Features](#features)
* [Dependencies](#dependencies)
* [Usage](#usage)
* [Compilation](#compilation)
* [Examples](#examples)
* [Contributing](#contributing)
* [License](#license)
* [Author](#author)

## Overview

This repository contains templated C++ implementations of common data structures covered in a Data Structures course. Each data structure is implemented in its own header file and is designed to be easy to integrate into your projects.

## Implemented Data Structures

* **Singly Linked List** (`SinglyLL.h`)
* **Stack (Linked List implementation)** (`Stacks.h`)
* **Queue** (`Queue.h`)
* **Max Heap** (`MaxHeap.h`)
* **Min Heap** (`MinHeap.h`)
* **Binary Search Tree** (`BinarySearchTree.h`)
* **Graph** (`Graph.h`) with support for:

  * Generic vertices and edges
  * Undirected graphs
  * Vertex search and traversal utilities

## Features

* **Templated classes** to support any data type.
* **Header-only** design: simply include the desired header in your project.
* **Basic operations**: insert, delete, search, traversal, and utility methods for each structure.
* **Graph utilities**: add/remove vertices and edges, compute vertex degrees, print adjacency lists.

## Dependencies

* A C++11 (or later) compatible compiler.

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/DataStructures.git
   cd DataStructures
   ```

2. Include the desired header in your source file:

   ```cpp
   #include "SinglyLL.h"
   #include "BinarySearchTree.h"
   // ...
   ```

3. Instantiate and use:

   ```cpp
   // Singly linked list of integers
   SinglyLL<int> list;
   list.Insert(new Node<int>(10));
   list.Print();  // Output: 10->NULL

   // Max heap of doubles
   MaxHeap<double> heap(100);
   heap.insert(3.14);
   heap.insert(2.71);
   heap.printContents();  // Output: 3.14	2.71
   ```

## Compilation

Compile your code with a C++11 (or later) standard flag, for example:

```bash
g++ -std=c++11 main.cpp -o main
```

## Contributing

Contributions, issues, and feature requests are welcome! Feel free to fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
