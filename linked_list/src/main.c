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
