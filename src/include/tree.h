/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-20 12:12:30
 * @LastEditTime: 2019-04-20 12:16:19
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

typedef struct tree
{
    TreeNode *root;
} Tree;

#endif
