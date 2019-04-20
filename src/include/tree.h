/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-20 12:12:30
 * @LastEditTime: 2019-04-20 13:32:31
 */
#ifndef TREE
#define TREE
#include "common.h"

typedef struct tree_node
{
    Element e; // the value
    struct tree_node *nextSibling;
    struct tree_node *firstChild;

} TreeNode;

// create an new treeNode
TreeNode *tree_node_new(Element e, TreeNode *nextSibling, TreeNode *firstChild);

typedef struct tree
{
    TreeNode *root; // the root treeNode 
    int size;       // the num of node
} Tree;

// create an empty tree
Tree *tree_new();


#endif
