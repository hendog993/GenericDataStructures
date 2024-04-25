#include "hashTable.h"
#include <stdlib.h>

int hash(int key, int size) 
{
    return abs(key) % size;
}

Node* HT_CreateNode(int32_t key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 0;
    newNode->next = NULL;
    return newNode;
}


HashTable* HT_CreateTable(int32_t size)
{
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (Node**)malloc(sizeof(Node*) * size);
    ht->size = size;
    for (size_t i = 0; i < size; i++) 
    {
        ht->table[i] = NULL;
    }
    return ht;
}


void HT_Insert(HashTable* ht, int32_t key)
{
    size_t index = hash(key, ht->size);
    Node* newNode = HT_CreateNode(key);

    if (ht->table[index] == NULL) 
    {
        ht->table[index] = newNode;
    }
    else 
    {
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}



bool HT_Search(HashTable* ht, int32_t key)
{
    size_t index = hash(key, ht->size);
    Node* current = ht->table[index];
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            return true; // Key found
        }
        current = current->next;
    }
    return false; // Key
}


int32_t HT_GetValueFromKey(HashTable* ht, int32_t key)
{
    size_t index = hash(key, ht->size);
    Node* current = ht->table[index];
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            return current->value; // Value associated with key found
        }
        current = current->next;
    }
    // If key is not found, return a default value (you may modify this behavior as needed)
    return -1;
}

void HT_FreeHashTable(HashTable* ht)
{
    for (size_t i = 0; i < ht->size; i++) 
    {
        Node* current = ht->table[i];
        while (current != NULL) 
        {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}
