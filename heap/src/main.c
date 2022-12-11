#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    node_t* root = NULL;

    // Insert some values into the binary heap.
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 8);
    insert(&root, 1);
    insert(&root, 7);

    // Print the binary heap.
    printf("Binary heap: ");
    print(root);
    printf("\n");

    // Get the minimum value in the binary heap.
    int min = get_min(root);
    printf("Minimum value: %d\n", min);

    // Remove the minimum value from the binary heap.
    remove_min(&root);

    // Print the binary heap after removing the minimum value.
    printf("Binary heap after removing the minimum value: ");
    print(root);
    printf("\n");

    // Extract the minimum value from the binary heap.
    int extracted = extract_min(&root);
    printf("Minimum value extracted: %d\n", extracted);

    // Print the binary heap after extracting the minimum value
    printf("Binary heap after extracting the minimum value: ");
    print(root);
    printf("\n");
    return 0;
}