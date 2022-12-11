#ifndef STACK_H
#define STACK_H


// Stack node
typedef struct StackNode {
  void *data;
  struct StackNode *next;
}StackNode;

// Stack
typedef struct Stack {
  StackNode *head;
  StackNode *tail;
  int size;
  int mode; // 0 = FIFO, 1 = LILO, 2 = LIFO, 3 = FILO
}Stack;

// Create a new stack
Stack *stack_new(int mode);

// Push an element onto the stack
void stack_push(Stack *stack, void *data);

// Pop an element off the stack
void *stack_pop(Stack *stack);

// Get the size of the stack
int stack_size(Stack *stack);

// Check if the stack is empty
int stack_is_empty(Stack *stack);

// Free the memory allocated for the stack
void stack_free(Stack *stack);

// Peek at the element on the top of the stack without removing it
void *stack_peek(Stack *stack);

// Clear the stack by removing all elements
void stack_clear(Stack *stack);

// Check if the stack contains a specific element
int stack_contains(Stack *stack, void *data);

// Reverse the order of the elements in the stack
void stack_reverse(Stack *stack);

// Convert the elements in the stack to an array
void **stack_to_array(Stack *stack);
void stack_iterate(Stack *stack, void (*fn)(void *data));
void print(void *data);
#endif
