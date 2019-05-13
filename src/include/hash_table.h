/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-05-13 11:32:35
 * @LastEditTime: 2019-05-13 17:40:50
 */

#ifndef HASH_TABLE
#define HASH_TABLE
#include "common.h"

struct hash_table_node;
typedef struct hash_table_node *HashTableNode;
HashTableNode make_empty_node(Element key, Element val);
HashTableNode put(HashTableNode n, Element key, Element val);
HashTableNode search(HashTableNode n, Element key, compare_func cmp);
HashTableNode remove(HashTableNode n, Element key, compare_func cmp);
void update(HashTableNode n, Element key, Element newVal, compare_func cmp);

struct hash_table;
typedef struct hash_table *HashTable;
HashTable make_empty(int capcity);
void put_val(HashTable table, Element key, Element val, hash_code_func code);
HashTableNode get(HashTable table, Element key, hash_code_func code, compare_func cmp);
int get_index(HashTable table, Element key, hash_code_func code);
// support copy-on-write
HashTable rehash(HashTable table, hash_code_func code);
void remove_val(HashTable table, Element key, hash_code_func code, compare_func cmp);
void update_val(HashTable table, Element key, Element newVal, compare_func cmp, hash_code_func code);

#endif
