# SList

SList is a templated, dynamic array-based list implementation in C++. It provides various functionalities to manipulate the list, such as adding, removing, searching elements, and checking properties of the list.

## Features

- **Dynamic resizing**: Automatically expands as elements are added.
- **Element access**: Access elements using the `at` method.
- **Insertion**: Add elements to the front, back, or at a specified index.
- **Deletion**: Remove elements from the front, back, or at a specified index.
- **Utilities**: Check if the list is sorted, palindromic, reverse the list, and more.
- **Search**: Linear and binary search implementations.

## Installation

To use SList in your project, simply include the header and implementation files in your project directory.

```cpp
#include "SList.h"
```

## Usage

Here is a basic example of how to use SList:

```cpp
#include <iostream>
#include "SList.h"

int main() {
    SList<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_front(0);
    myList.insertAt(3, 2);

    std::cout << "List size: " << myList.size() << std::endl;

    myList.pop_back();
    myList.pop_front();

    if (myList.isSorted()) {
        std::cout << "The list is sorted." << std::endl;
    }

    myList.reverse();

    int index = myList.find(2);
    if (index != -1) {
        std::cout << "Element 2 found at index " << index << std::endl;
    }

    return 0;
}
```

## API Reference

### `SList`

#### Private Members:
- `int _size`: Current size of the list.
- `int _maxIdx`: The highest index with a valid element.
- `T* arr`: Pointer to the dynamic array holding list elements.
- `T defaultBuffer`: Default buffer to return when accessing out-of-bounds elements.

#### Public Methods:

- **Constructor & Destructor**
  - `SList()`: Initializes an empty list.
  - `~SList()`: Cleans up allocated memory.

- **Insertion**
  - `bool push_back(const T &ele)`: Adds an element to the end of the list.
  - `bool push_front(const T &ele)`: Adds an element to the front of the list.
  - `bool insertAt(const T &ele, const int &i)`: Inserts an element at index `i`.

- **Deletion**
  - `bool pop_back()`: Removes the last element.
  - `bool pop_front()`: Removes the first element.
  - `bool popAt(const T &ele, const int &index)`: Removes an element at index `index`.

- **Access & Information**
  - `int size() const`: Returns the number of elements.
  - `T& at(const int &index) const`: Returns a reference to the element at `index`.
  - `T* begin() const`: Returns a pointer to the first element.
  - `T* end() const`: Returns a pointer to one past the last element.

- **Utilities**
  - `bool isSorted() const`: Checks if the list is sorted.
  - `bool isPalindromic() const`: Checks if the list is palindromic.
  - `void reverse()`: Reverses the list.
  - `int find(const T &ele) const`: Finds the first occurrence of an element.
  - `int findAfter(const T &ele, int index) const`: Finds the first occurrence of an element after a specified index.
  - `int count(const T &ele) const`: Counts occurrences of an element.
  - `int binarySearch(const T &ele)`: Searches for an element using binary search (requires the list to be sorted).

## Compilation

Ensure you compile your project with the appropriate compiler flags. For example:

```bash
g++ -o myProgram main.cpp SList.h
```

## Contributing

Feel free to submit issues or pull requests if you find bugs or have improvements.

## License

This project is licensed under the MIT License.

---

Happy coding!
