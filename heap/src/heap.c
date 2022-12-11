#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the binary heap.
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node_t;

// Creates a new node with the given value.
node_t* create_node(int value) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Inserts a new element into the binary heap.
void insert(node_t** root, int value) {
// If the tree is empty, create a new root node.
    if (*root == NULL) {
        *root = create_node(value);
        return;
    }

    // If the value to insert is greater than the root value, insert the element to the right.
    if (value > (*root)->value) {
        insert(&(*root)->right, value);
    }
    // Otherwise, insert the element to the left.
    else {
        insert(&(*root)->left, value);
    }
}

// Returns the minimum value in the binary heap.
int get_min(node_t* root) {
    // If the heap is empty, return -1.
    if (root == NULL) {
        return -1;
    }

    int min_left = get_min(root->left);
    int min_right = get_min(root->right);
    // The minimum value in the heap is the minimum of the values at the root and in the left and right subtrees.
    int min = root->value;
    if (min_left != -1 && min_left < min) {
        min = min_left;
    }
    if (min_right != -1 && min_right < min) {
        min = min_right;
    }

    return min;
}

// Removes the minimum value from the binary heap.
void remove_min(node_t** root) {
    // If the heap is empty, return.
    if (*root == NULL) {
        return;
    }

    // If the heap only has one node, free it and set the root to NULL.
    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
        return;
    }

    // Find the minimum value in the left subtree of the root.
    int min_left = get_min((*root)->left);

    // If the root contains the minimum value, remove it and return.
    if ((*root)->value == min_left) {
        free(*root);
        *root = NULL;
        return;
    }

    // Otherwise, recursively remove the minimum value from the left subtree.
    remove_min(&(*root)->left);
}

// Removes and returns the minimum value from the binary heap.
int extract_min(node_t** root) {
    // If the heap is empty, return -1.
    if (*root == NULL) {
        return -1;
    }

    // The minimum value is always at the root of the heap, so store it in a variable.
    int min = get_min(*root);

    // Remove the minimum value from the heap by calling remove_min.
    remove_min(root);

    // Return the minimum value.
    return min;
}


void print(node_t* root) {
    if (root == NULL) {
        return;
    }

    print(root->left);
    printf("%d ", root->value);
    print(root->right);
}