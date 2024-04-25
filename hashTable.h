/*
*  Filename:
*       hashTable.h
* 
*  Description:
*       Generic implementation of integer hash table key-value pairs. 
*/


#ifndef HASH_TABLE_H
#define HASH_TABLE_H


#include <stdint.h>

// Hash Table Node Structure
typedef struct Node
{
    int32_t key;
    int32_t value;
    struct Node* next;
} Node;

// Hash Table Structure
typedef struct
{
    Node** table;
    size_t size;
} HashTable;



/*
* Function:
*       HT_CreateNode
*
* Description:
*       Creates a single node to a hash table using dynamic memory allocation 
*
* Return:
*       Poiner to newly created node in dynamic memory 
*/
Node* HT_CreateNode(int32_t key);




/*
* Function:
*       HT_CreateTable
* 
* Description:
*       Creates a hash table in dynamic memory. 
* 
* Return:
*       Pointer to hash table in heap 
*/
HashTable* HT_CreateTable(int32_t size);

/*
* Function:
*       HT_Insert
*
* Description:
*       Inserts an entry into the hash table using the specified input key
*
* Return:
*
*/
void HT_Insert(HashTable* ht, int32_t key);



/*
* Function:
*       HT_Search
*
* Description:
*       Searches a hash table based on the input key and returns true if the key exists 
*
* Return:
*       True if key exists, false otherwise 
*/
bool HT_Search(HashTable* ht, int32_t key);

/*
* Function:
*       HT_GetValueFromKey
*
* Description:
*       Returns the entry value based on input key. Returns -1 if invalid - TODO this should be avoided 
*
* Return:
*
*/
int32_t HT_GetValueFromKey(HashTable* ht, int32_t key);

/*
* Function:
*
*
* Description:
*
*
* Return:
*
*/
void HT_FreeHashTable(HashTable* ht);

#endif 
