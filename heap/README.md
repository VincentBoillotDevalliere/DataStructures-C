# Binary Heap Implementation in C

This repository provides an easy-to-use implementation of a binary heap in C, with functions for inserting, removing, and getting the minimum value in the heap.

## Features

- Simple and efficient implementation of a binary heap in C
- Functions for inserting, removing, and getting the minimum value in the heap
- Well-documented code for easy understanding and customization

4. Build the binary heap implementation by running the `make` command:

$ make

## Usage

To use the binary heap implementation, include the `binary-heap.h` header file in your C source code:

```c
#include "binary-heap.h"
``` 

Then, create a new binary heap by calling the `create_node` function, passing the value to insert at the root of the heap:
```c
node_t* root = create_node(42);
``` 

To insert additional values into the heap, call the `insert` function, passing a pointer to the root of the heap and the value to insert:
```c
insert(&root, 17);
insert(&root, 31);
insert(&root, 13);
``` 

To get the minimum value in the heap, call the `get_min` function, passing a pointer to the root of the heap:
```c
int min = get_min(root);
```

To remove the minimum value from the heap, call the `remove_min` function, passing a pointer to the root of the heap:
```c
remove_min(&root);

```
## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.