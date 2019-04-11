/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 11:18:50
 * @LastEditTime: 2019-04-11 11:28:50
 */
#ifndef BINARY_TREE
#define BINARY_TREE

#include "common.h"

typedef struct binary_tree_node
{
    Element element;
    binary_tree_node *left;  // left child node
    binary_tree_node *right; // right child node

} BinaryTreeNode;

BinaryTreeNode *binary_tree_node_new(Element e, BinaryTreeNode *left, BinaryTreeNode *right);

typedef struct binary_tree
{
    BinaryTreeNode *root;
    int size;
} BinaryTree;

BinaryTree *binary_tree_new();

void add(Element e, BinaryTree *tree);

#endif
