#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100

// Define the structure of a hash table entry
struct HashEntry {
    char* key;
    int value;
    struct HashEntry* next;
};

// Define the structure of a hash table
struct HashTable {
    struct HashEntry* table[TABLE_SIZE];
};

// Function to create a new hash entry
struct HashEntry* createEntry(const char* key, int value) {
    struct HashEntry* newEntry = (struct HashEntry*)malloc(sizeof(struct HashEntry));
    if (newEntry == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = NULL;
    return newEntry;
}
// Function to compute the hash index
unsigned int hashFunction(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
    hash = hash * 31 + key[i];
    }
    return hash % TABLE_SIZE;
}
// Function to insert a key-value pair into the hash table
void insert(struct HashTable* ht, const char* key, int value) {
    unsigned int index = hashFunction(key);
    struct HashEntry* newEntry = createEntry(key, value);
    if (ht->table[index] == NULL) {
        ht->table[index] = newEntry;
    } 
    else {
        struct HashEntry* current = ht->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }
}

// Function to retrieve a value from the hash table
int get(struct HashTable* ht, const char* key) {
    unsigned int index = hashFunction(key);
    struct HashEntry* current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}
// Function to free the memory occupied by the hash table
void freeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct HashEntry* current = ht->table[i];
        while (current != NULL) {
            struct HashEntry* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
}
int main() {
    struct HashTable ht;
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht.table[i] = NULL;
    }
    insert(&ht, "apple", 5);
    insert(&ht, "banana", 10);
    insert(&ht, "cherry", 15);
    printf("Value for 'apple': %d\n", get(&ht, "apple")); // Output: Value for 'apple': 5
    printf("Value for 'banana': %d\n", get(&ht, "banana")); // Output: Value for 'banana': 10
    printf("Value for 'cherry': %d\n", get(&ht, "cherry")); // Output: Value for 'cherry': 15
    printf("Value for 'grape': %d\n", get(&ht, "grape")); // Output: Value for 'grape': -1
    freeHashTable(&ht);
    return 0;
}