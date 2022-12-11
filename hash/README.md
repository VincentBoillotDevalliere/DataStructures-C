# Hash Map

A hash map is a data structure that allows efficient insertion, deletion, and lookup of values based on keys. It uses a hash function to map keys to indices in an array, so that each key can be quickly found or inserted without having to compare every element in the array.

## Why Use a Hash Map?

Hash maps are useful when you need to store a large number of key-value pairs and perform frequent operations like insertion, deletion, and lookup. They offer faster performance than other data structures like linked lists or binary trees, because they use a hash function to quickly map keys to indices in an array.

## How to Use a Hash Map in C

To use a hash map in C, you can include the hashmap.h header file in your code, and then call the hashmap_new() function to create a new hash map. This function takes the size of the hash map as an argument, and returns a pointer to the newly created hash map.

Here is an example of how to create a new hash map with a size of 10:

```c
#include "hashmap.h"

// Create a new hash map with a size of 10
HashMap *map = hashmap_new(10);
```
Once you have created a hash map, you can use the hashmap_set() function to add key-value pairs to the map. This function takes the hash map, the key, and the value as arguments, and adds the key-value pair to the map. If the key already exists in the map, the function updates its value with the new value.

Here is an example of how to set a value in the hash map:
```c
// Set a value in the hash map
hashmap_set(map, "key", "value");
```
To retrieve a value from the hash map, you can use the hashmap_get() function. This function takes the hash map and the key as arguments, and returns the value associated with the key. If the key does not exist in the map, the function returns NULL.

Here is an example of how to get a value from the hash map:
```c
// Get a value from the hash map
void *value = hashmap_get(map, "key");
```
You can also use the hashmap_contains() function to check ifthe hash map contains a specific key. This function takes the hash map and the key as arguments, and returns 1 if the key exists in the map, and 0 otherwise.

Here is an example of how to check if a key exists in the hash map:
```c
// Check if a key exists in the hash map
int contains = hashmap_contains(map, "key");
```
To remove a key-value pair from the hash map, you can use the hashmap_remove() function. This function takes the hash map and the key as arguments, and removes the key-value pair from the map. If the key does not exist in the map, the function does nothing.

Here is an example of how to remove a key-value pair from the hash map:
```c
// Remove a key-value pair from the hash map
hashmap_remove(map, "key");
```
The hash map also provides the hashmap_iterate() function, which allows you to iterate over all keys and values in the map. This function takes the hash map and a callback function as arguments, and calls the callback function for each key-value pair in the map. The callback function takes the key and value as arguments, and can be used to perform some operation on each key-value pair.

Here is an example of how to iterate over all keys and values in the hash map:
```c
// Iterate over all keys and values in the hash map
hashmap_iterate(map, [](const char *key, void *value) {
  printf("- key: %s, value: %s\n", key, (char *) value);
});
```
Finally, you can use `the hashmap_size()` function to get the number of key-value pairs in the hash map. This function takes the hash map as an argument, and returns the number of key-value pairs in the map.

Here is an example of how to get the size of the hash map:
```c
// Get the size of the hash map
int size = hashmap_size(map);
```
When you are done using the hash map, you can call the hashmap_free() function to free the memory allocated for the map. This function takes the hash map as an argument, and frees all memory associated with the map.

Here is an example of how to free a hash map:
```c
// Free the memory allocated for the hash map
hashmap_free(map);
```
That's it! You now know how to use a hash map data structure in C. I hope this brief README has been helpful in explaining why hash maps are useful and how to use them in your code. Happy coding!