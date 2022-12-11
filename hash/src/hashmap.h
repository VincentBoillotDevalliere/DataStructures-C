#ifndef HASMAP_H
#define HASMAP_H


typedef struct HashMapNode {
    char *key;
    void *value;
    struct HashMapNode *next;
} HashMapNode;

// Hash map
typedef struct {
    int size;
    HashMapNode **nodes;
} HashMap;


unsigned int hash(const char *key);
void *hashmap_get(HashMap *map, const char *key);
HashMap *hashmap_new(int size);
void hashmap_set(HashMap *map, const char *key, void *value);
void hashmap_free(HashMap *map);
int hashmap_contains(HashMap *map, const char *key) ;
void hashmap_remove(HashMap *map, const char *key);
void hashmap_iterate(HashMap *map, void (*fn)(const char *key, void *value));
int hashmap_size(HashMap *map);
void print_map_element(const char *key, void *value);
#endif // BINARY_HEAP_H