/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-24 09:33:18
 * @LastEditTime: 2019-04-24 13:24:27
 */

#ifndef B_TREE
#define B_TREE
#include "common.h"
#define M 4 // define the

struct BTreeNode;
typedef struct BTreeNode *Position;
typedef struct BTreeNode *BTree;
BTree make_empty();
Position find(Element e, BTree t, compare_func cmp);
BTree insert(Element e, BTree t, compare_func cmp);
BTree remove(Element e, BTree t, compare_func cmp);

#endif
