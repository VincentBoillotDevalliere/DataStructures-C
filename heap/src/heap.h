// binary_heap.h
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

typedef struct node node_t;

node_t* create_node(int value);
void insert(node_t** root, int value);
void print(node_t* root);
int extract_min(node_t** root);
void remove_min(node_t** root);
int get_min(node_t* root);
#endif // BINARY_HEAP_H