
### EE200 Homework Assignment: Templated PriorityQueue Class in C++

#### Project Overview
This project implements a templated `PriorityQueue` class in C++ using a max-heap as the underlying data structure. The goal is to provide a robust and efficient priority queue capable of handling any data type that supports comparison operators. The implementation focuses on simplicity, avoiding manual memory management by leveraging standard containers such as `std::vector`.

#### Features
- **Constructors**:
  - Default constructor for initializing an empty priority queue.
  - Copy constructor to create deep copies of `PriorityQueue` instances.
- **Destructor**: Ensures clean-up of any dynamically allocated resources.
- **Core Operations**:
  - `size()`: Returns the number of elements in the queue.
  - `top()`: Retrieves the highest-priority element without removing it.
  - `push(T x)`: Inserts an element into the queue while maintaining heap properties.
  - `pop()`: Removes the highest-priority element.
- **Operator Overloading**:
  - Assignment operator performs deep copying of the heap structure.
- **Heap Implementation**:
  - Custom heap management ensures elements are maintained in max-heap order, supporting efficient insertion and deletion.

#### Implementation Highlights
- **Templating**: Allows the class to support any data type that implements comparison operators (`<`, `>`, `==`, `!=`).
- **Heap Management**: Uses `std::vector` as the underlying container, with custom logic for maintaining max-heap properties.
- **Encapsulation**: Implementation details are kept private, exposing only the necessary public interface.
- **Valgrind-Clean**: Ensures no memory leaks or invalid accesses.

#### Testing
Comprehensive test cases validate the functionality of the `PriorityQueue`:
- Core operations (`push`, `pop`, `top`) for various data types.
- Edge cases, such as empty queues and large datasets.
- Correctness of deep copying with the copy constructor and assignment operator.
- Efficiency of heap operations under varying input conditions.

#### Repository Content
- **Source Code**: Implementation of the `PriorityQueue` class.
- **Makefile**: Build system for compiling and running tests.
- **Test Files**: Unit tests to verify correctness and performance of the priority queue.

#### Authors
Gabby Beddard. Project completed as part of a data structures course focusing on heap-based implementations and templated data structures in C++.
