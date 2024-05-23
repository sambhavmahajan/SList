# SList: List Implementation in C++

'SList' is a data structures that provides basic functionalities such as insertion, deletion, searching, sorting check, reversing, and more.

## Features

- Insertion of elements at the back, front, or at a specified position
- Deletion of elements from the back, front, or at a specified position
- Checking if the list is sorted
- Checking if the list is palindromic
- Reversing the list
- Searching for elements using linear search or binary search (for sorted lists)
- Accessing elements by index
- Iterating over the list using iterators

## Usage

To use the `SList` class in your C++ project, follow these steps:

1. Include the `SList.h` header file in your project.
2. Instantiate an object of `SList` with the desired data type.
3. Use the provided member functions to manipulate the list as needed.

Here's a simple example:

```cpp
#include "SList.h"
#include <iostream>

int main() {
    SList<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    std::cout << "Size of list: " << myList.size() << std::endl;

    return 0;
}
```

## Contributions

Contributions to this project are welcome! If you find any bugs or have suggestions for improvements, please open an issue or create a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.txt) file for details.
