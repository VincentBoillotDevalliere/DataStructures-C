#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Create a new node
struct node *create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error creating a new node.\n");
    exit(0);
  }

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

// Insert a new node at the head of the list
void prepend(struct node **head_ref, int data) {
  struct node *new_node = create_node(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Insert a new node at the end of the list
void append(struct node **head_ref, int data) {
  struct node *new_node = create_node(data);

  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  struct node *current = *head_ref;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

// Delete a node from the list
void delete(struct node **head_ref, int data) {
  struct node *current = *head_ref;
  struct node *previous = NULL;

  if (current == NULL) {
    return;
  }

  while (current->data != data) {
    if (current->next == NULL) {
      return;
    } else {
      previous = current;
      current = current->next;
    }
  }

  if (current == *head_ref) {
    *head_ref = (*head_ref)->next;
  } else {
    previous->next = current->next;
  }

  free(current);
}

// Find a node in the list by its value
struct node *find(struct node *head, int data) {
  struct node *current = head;

  while (current != NULL) {
    if (current->data == data) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

// Reverse the order of the nodes in the list
void reverse(struct node **head_ref) {
  struct node *previous = NULL;
  struct node *current = *head_ref;
  struct node *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  *head_ref = previous;
}


// Print the values of the nodes in the list
void display(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}
