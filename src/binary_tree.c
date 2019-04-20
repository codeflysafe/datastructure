/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-20 17:11:05
 * @LastEditTime: 2019-04-20 17:32:19
 */
#include "include/binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

BinaryTreeNode *binary_tree_node_new(Element e, BinaryTreeNode *left, BinaryTreeNode *right)
{
    BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node->element = e;
    node->left = left;
    node->right = right;
    return node;
}

BinaryTree *binary_tree_new()
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(
        BinaryTree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void *binary_tree_preorder(BinaryTreeNode *node)
{
    if (node)
    {
        printf("%p", node->element);
        binary_tree_preorder(node->left);
        binary_tree_preorder(node->right);
    }
}

void *binary_tree_postorder(BinaryTreeNode *node)
{
    if (node)
    {
        binary_tree_preorder(node->left);
        binary_tree_preorder(node->right);
        printf("%p", node->element);
    }
}

void *binary_tree_inorder(BinaryTreeNode *node)
{
    if (node)
    {
        binary_tree_preorder(node->left);
        printf("%p", node->element);
        binary_tree_preorder(node->right);
    }
}
