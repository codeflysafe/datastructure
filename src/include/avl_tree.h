/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 11:29:10
 * @LastEditTime: 2019-04-23 23:00:11
 */

#ifndef AVL_TREE
#define AVL_TREE
#include "common.h"

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

// clear the avl tree
AvlTree make_empty(AvlTree t);

Position find(Element e, AvlTree t, compare_func cmp);

Position find_min(AvlTree t);

AvlTree find_max(AvlTree t);

AvlTree insert(Element e, AvlTree t, compare_func cmp);

AvlTree remove(Element e, AvlTree t, compare_func cmp);

int height(Position t);

#endif
