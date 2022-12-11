#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
// Hash map node

// Hash function
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = hash * 33 + *key++;
    }
    return hash;
}

// Create a new hash map
HashMap *hashmap_new(int size) {
    HashMap *map = malloc(sizeof(HashMap));
    map->size = size;
    map->nodes = calloc(size, sizeof(HashMapNode));
    return map;
}

// Set a value in the hash map
void hashmap_set(HashMap *map, const char *key, void *value) {
    unsigned int index = hash(key) % map->size;
    HashMapNode *node = map->nodes[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    HashMapNode *new_node = malloc(sizeof(HashMapNode));
    new_node->key = malloc(strlen(key) + 1);
    strcpy(new_node->key, key);
    
    new_node->value = malloc(strlen(value) + 1);
    strcpy(new_node->value, value);

    new_node->next = map->nodes[index];
    map->nodes[index] = new_node;
}

// Get a value from the hash map
void *hashmap_get(HashMap *map, const char *key) {
    unsigned int index = hash(key) % map->size;
    HashMapNode *node = map->nodes[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

// Free a hash map
void hashmap_free(HashMap *map) {
  for (int i = 0; i < map->size; i++) {
    HashMapNode *node = map->nodes[i];
    while (node) {
      HashMapNode *next = node->next;
      free(node->key);
      free(node->value);
      free(node);
      node = next;
    }
  }
  free(map->nodes);
  free(map);
}


// Check if a key exists in the hash map
int hashmap_contains(HashMap *map, const char *key) {
  unsigned int index = hash(key) % map->size;
  HashMapNode *node = map->nodes[index];
  while (node) {
    if (strcmp(node->key, key) == 0) {
      return 1;
    }
    node = node->next;
  }
  return 0;
}

// Remove a key from the hash map
void hashmap_remove(HashMap *map, const char *key) {
  unsigned int index = hash(key) % map->size;
  HashMapNode *node = map->nodes[index];
  HashMapNode *prev = NULL;
  while (node) {
    if (strcmp(node->key, key) == 0) {
      if (prev) {
        prev->next = node->next;
      } else {
        map->nodes[index] = node->next;
      }
      free(node->key); // <-- libérer la mémoire allouée pour la clé
      free(node->value);
      free(node);
      return;
    }
    prev = node;
    node = node->next;
  }
}
// Iterate over all keys and values in the hash map
void hashmap_iterate(HashMap *map, void (*fn)(const char *key, void *value)) {
  for (int i = 0; i < map->size; i++) {
    HashMapNode *node = map->nodes[i];
    while (node) {
      fn(node->key, node->value);
      node = node->next;
    }
  }
}

// Get the number of key-value pairs in the hash map
int hashmap_size(HashMap *map) {
  int size = 0;
  for (int i = 0; i < map->size; i++) {
    HashMapNode *node = map->nodes[i];
    while (node) {
      size++;
      node = node->next;
    }
  }
  return size;
}