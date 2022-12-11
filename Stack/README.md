# Stack

The Stack data structure is a simple and efficient way to store and manipulate a collection of items in a Last-In-First-Out (LIFO) or First-In-First-Out (FIFO) manner. This implementation allows the stack to be used in a variety of modes, including LIFO, LILO, FIFO and FILO.

## Features

    Simple and efficient LIFO/FIFO data structure.
    Supports multiple stack modes: LIFO, LILO, FIFO and FILO.
    Dynamic array implementation for automatic resizing.
    Various stack operations: push, pop, peek, clear, etc.
    Stack iteration and conversion to array.

## Usage

To use the Stack data structure, include the stack.h header file in your code and call the stack_new function to create a new stack. The stack_new function takes the maximum size of the stack as a parameter and returns a pointer to a Stack object.
```c
#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]) {
  // Create a new LIFO stack
  Stack *stack = stack_new(10);

  // Push some elements onto the stack
  stack_push(stack, "Hello");
  stack_push(stack, "World");

  // Pop an element from the stack
  char *str = stack_pop(stack);
  printf("Popped: %s\n", str);

  // Free the memory allocated for the stack
  stack_free(stack);

  return 0;
}
```
The Stack object provides various functions for manipulating the stack, such as stack_push to push an element onto the stack, stack_pop to pop an element from the stack, and stack_peek to peek at the top element on the stack without removing it. The stack_reverse function can be used to reverse the order of the elements in the stack, and the stack_to_array function can be used to convert the stack to an array of void * pointers.

The stack_iterate function can be used to iterate over all elements in the stack, and the stack_contains function can be used to check if the stack contains a specific element. The stack_is_empty and stack_size functions can be used to check the current state of the stack.

For more information on the available functions and their usage, see the stack.h header file.

## License

This project is licensed under the MIT License. See the LICENSE file for details.