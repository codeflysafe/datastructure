/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-22 12:23:24
 * @LastEditTime: 2019-04-22 13:24:42
 */

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "common.h"

struct binary_search_tree_node;
typedef struct binary_search_tree_node TreeNode;
typedef TreeNode *Position;
typedef TreeNode *SearchTree;

TreeNode *tree_node_new(Element e, SearchTree left, SearchTree right);

// make the tree to empty
SearchTree
make_empty(SearchTree t);
// find the node whoese value is e
Position find(Element e, SearchTree t, compare_func cmp);
// find the min value in this tree
Position find_min(SearchTree t);
// find the max value in this tree
Position find_max(SearchTree t);
// insert an element to tree
SearchTree insert(Element e, SearchTree t, compare_func cmp);
// remove an element from tree
SearchTree remove(Element e, SearchTree t, compare_func cmp);

#endif
