#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
  int data;
  struct node *next;
};

struct node *create_node(int data);
void prepend(struct node **head_ref, int data);
void append(struct node **head_ref, int data);
void delete(struct node **head_ref, int data);
struct node *find(struct node *head, int data);
void reverse(struct node **head_ref);
void display(struct node *head);
#endif
