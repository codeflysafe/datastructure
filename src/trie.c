/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-05-09 11:31:27
 * @LastEditTime: 2019-05-13 11:16:42
 */

#include "include/trie.h"
#include <stdlib.h>

// the trie node define
struct trie_node
{
    int code;  // the code of element
    int depth; // depth is the level of node
    int left;  // the left limit
    int right; // the right limit
};

// the trie entity define
// base[s] + c = t
// check[t] = s
struct trie
{
    // two array have same capacity
    int *base;
    int *check;
    boolean *use;
    int cap;
};

void extend_capacity(Trie t, int new_cap)
{
    t->base = realloc(t->base, new_cap * sizeof(int));
    t->check = realloc(t->check, new_cap * sizeof(int));
    t->use = realloc(t->use, new_cap * sizeof(boolean));
    t->cap = new_cap;
}
