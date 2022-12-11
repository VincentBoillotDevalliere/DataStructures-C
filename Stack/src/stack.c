#include <stdlib.h>
#include "stack.h"


// Create a new stack
Stack *stack_new(int mode) {
  Stack *stack = malloc(sizeof(Stack));
  stack->head = NULL;
  stack->tail = NULL;
  stack->size = 0;
  stack->mode = mode;
  return stack;
}

// Push an element onto the stack
void stack_push(Stack *stack, void *data) {
  StackNode *node = malloc(sizeof(StackNode));
  node->data = data;
  node->next = NULL;
  if (stack->head == NULL) {
    stack->head = node;
    stack->tail = node;
  } else {
    switch (stack->mode) {
      case 0: // FIFO
        stack->tail->next = node;
        stack->tail = node;
        break;
      case 1: // LILO
        node->next = stack->head;
        stack->head = node;
        break;
      case 2: // LIFO
        node->next = stack->head;
        stack->head = node;
        break;
      case 3: // FILO
        stack->tail->next = node;
        stack->tail = node;
        break;
    }
  }
  stack->size++;
}

// Pop an element off the stack
void *stack_pop(Stack *stack) {
    if (stack->size == 0) {
        return NULL;
    }
    StackNode *node = stack->head;
    void *data = node->data;
    stack->head = node->next;
    if (stack->head == NULL) {
        stack->tail = NULL;
    }
    free(node);
    stack->size--;
    return data;
}

// Get the size of the stack
int stack_size(Stack *stack) {
    return stack->size;
}

// Check if the stack is empty
int stack_is_empty(Stack *stack) {
    return stack->size == 0;
}

// Free the memory allocated for the stack
void stack_free(Stack *stack) {
    StackNode *node = stack->head;
    while (node) {
        StackNode *next = node->next;
        free(node);
        node = next;
    }
    free(stack);
}

// Peek at the element on the top of the stack without removing it
void *stack_peek(Stack *stack) {
  if (stack_is_empty(stack)) {
    return NULL;
  }
  return stack->head->data;
}

// Clear the stack by removing all elements
void stack_clear(Stack *stack) {
  StackNode *node = stack->head;
  while (node) {
    StackNode *next = node->next;
    free(node);
    node = next;
  }
  stack->head = NULL;
  stack->tail = NULL;
  stack->size = 0;
}

// Check if the stack contains a specific element
int stack_contains(Stack *stack, void *data) {
  StackNode *node = stack->head;
  while (node) {
    if (node->data == data) {
      return 1;
    }
    node = node->next;
  }
  return 0;
}

// Reverse the order of the elements in the stack
void stack_reverse(Stack *stack) {
  StackNode *prev = NULL;
  StackNode *current = stack->head;
  while (current) {
    StackNode *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  stack->tail = stack->head;
  stack->head = prev;
}

// Convert the elements in the stack to an array
void **stack_to_array(Stack *stack) {
  void **array = malloc(stack->size * sizeof(void *));
  StackNode *node = stack->head;
  int i = 0;
  while (node) {
    array[i++] = node->data;
    node = node->next;
  }
  return array;
}

void stack_iterate(Stack *stack, void (*fn)(void *data)) {
  StackNode *node = stack->head;
  while (node) {
    fn(node->data);
    node = node->next;
  }
}