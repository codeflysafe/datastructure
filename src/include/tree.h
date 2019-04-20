/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-20 12:12:30
 * @LastEditTime: 2019-04-20 15:25:13
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

void tree_list(Tree *tree, Element *elements);
// return the array of tree preorder result
void tree_preorder(TreeNode *node, Element *elements);

// return the result of postorder
void tree_postorder(TreeNode *node, Element *elements);

// return the result of level order
void tree_levelorder(TreeNode *node, Element *elements);

#endif
