/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-05-13 11:38:01
 * @LastEditTime: 2019-05-13 17:31:57
 */

#include "include/hash_table.h"
#include <stdlib.h>
// hash table node
// just an double linked list
struct hash_table_node
{
    struct hash_table_node *next;
    struct hash_table_node *prev;
    Element key; // the key
    Element val; // the value
};

HashTableNode make_empty_node(Element key, Element val)
{
    HashTableNode node = (HashTableNode)malloc(sizeof(HashTableNode));
    node->key = key;
    node->val = val;
    return node;
};

//
HashTableNode
put(HashTableNode n, Element key, Element val)
{
    HashTableNode temp = make_empty_node(key, val);
    temp->next = n;
    temp->prev = NULL;
    n->next = temp;
    n->prev = temp;
    return temp;
};

HashTableNode
search(HashTableNode n, Element key, compare_func cmp)
{
    HashTableNode temp = n;
    while (temp != NULL)
    {
        if (cmp(temp->key, key) == 0)
        {
            return temp;
        }
    }
    return NULL;
};

HashTableNode remove(HashTableNode n, Element key, compare_func cmp)
{
    HashTableNode temp = search(n, key, cmp);
    if (temp != NULL)
    {
        HashTableNode prev = temp->prev;
        HashTableNode next = temp->next;
        if (prev != NULL && next != NULL)
        {
            prev->next = next;
            next->prev = prev;
            free(temp);
        }
        else if (prev != NULL)
        {
            prev->next = next;
            free(temp);
        }
        else
        {
            next->prev = NULL;
            free(temp);
            return next;
        }
    }
    return n;
};

// the hash table define
struct hash_table
{
    HashTableNode *bucket;
    int length;   // the len of bucket
    float factor; // the factor of impact
    int size;     // the current size of nodes
    int threshold;
};

// make an empty hash table
HashTable make_empty(int capcity)
{
    if (capcity <= 0)
    {
        capcity = DEFAULT_CAPACITY;
    }
    HashTableNode *bucket = (HashTableNode *)malloc(capcity * sizeof(HashTableNode));
    HashTable table = (HashTable)malloc(sizeof(HashTable));
    table->bucket = bucket;
    table->factor = IMPACT_FACTOR;
    table->length = capcity;
    table->size = 0;
    table->threshold = capcity * IMPACT_FACTOR;
    return table;
};

// put value to hash table
void put_val(HashTable table, Element key, Element val, hash_code_func code)
{
    if (table == NULL)
    {
        table = make_empty(0);
    }
    if (table->size >= table->threshold)
    {
        table = rehash(table, code);
    }
    int idx = get_index(table, key, code);
    put(table->bucket[idx], key, val);
    return;
}

int get_index(HashTable table, Element key, hash_code_func code)
{
    int c = code(key);
    return c % table->length;
}

HashTable rehash(HashTable table, hash_code_func code)
{
    if (table->length >= MAXIMUM_CAPACITY)
    {
        return table;
    }
    HashTable t;
    if (table->length << 1 >= MAXIMUM_CAPACITY)
    {
        t = make_empty(MAXIMUM_CAPACITY);
    }
    else
    {
        t = make_empty(table->length << 1);
    }

    for (int i = 0; i < t->length; i++)
    {
        HashTableNode n = t->bucket[i];
        while (n != NULL)
        {
            HashTableNode temp = n->next;
            put_val(t, n->key, n->val, code);
            free(n);
            n = temp;
        }
    }
    free(table);
    return t;
}

void remove_val(HashTable table, Element key, hash_code_func code, compare_func cmp)
{
    int idx = get_index(table, key, code);
    table->bucket[idx] = remove(table->bucket[idx], key, cmp);
    return;
}

