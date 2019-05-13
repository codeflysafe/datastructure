/*
 * @Description:  Translate from https://github.com/komiya-atsushi/darts-java/blob/master/src/main/java/darts/DoubleArrayTrie.java
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-05-09 11:31:18
 * @LastEditTime: 2019-05-13 10:44:23
 */
#ifndef TRIE
#define TRIE
#include "common.h"
#define INIT_CAP 10

struct trie_node;
struct trie;

typedef struct trie_node *TrieNode;
typedef struct trie *Trie;

// extend the capacity
void extend_capacity(Trie t, int new_cap);

Trie make_empty(Trie t);

void insert(Trie t, int code);

#endif
