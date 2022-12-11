Linked List

This code provides an implementation of a linked list in C. It includes functions for creating a new node, inserting a node at the head or end of the list, deleting a node from the list, finding a node by its value, reversing the order of the nodes in the list, and printing the values of the nodes in the list.
Advantages

    The linked list data structure allows for fast insertion and deletion of elements.
    It is a dynamic data structure, allowing it to grow and shrink in size as needed.
    Linked lists can be used to implement other data structures, such as stacks and queues.

Usage

To use this code, you will need to include the header file linked_list.h in your code, and call the functions declared in the header file to manipulate the linked list.

Here is an example of how to use the code to create a linked list, append some nodes to it, prepend a node to it, delete a node from it, find a node by its value, reverse the order of the nodes in the list, and print the values of the nodes in the list:

```c	
#include <stdio.h>
#include "linked_list.h"

int main() {
  // Create an empty list
  struct node *head = NULL;

  // Append some nodes to the list
  append(&head, 1);
  append(&head, 2);
  append(&head, 3);

  // Prepend a node to the list
  prepend(&head, 0);

  struct node *node = find(head, 2);
  if (node != NULL) {
    printf("Node found with value: %d\n", node->data);
  } else {
    printf("Node not found in the list\n");
  }

  // Delete a node from the list
  delete(&head, 2);

  display(head);

  node = find(head, 2);
  if (node != NULL) {
    printf("Node found with value: %d\n", node->data);
  } else {
    printf("Node not found in the list\n");
  }


  printf("Reverse the list\n");
  // Reverse the list
  reverse(&head);

  display(head);
}

```