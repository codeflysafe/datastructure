/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-20 14:57:48
 * @LastEditTime: 2019-04-20 15:44:37
 */

#include "include/tree.h"
#include <stdlib.h>
#include "include/queue.h"

TreeNode *tree_node_new(Element e, TreeNode *firstChild, TreeNode *nextSibling)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->e = e;
    node->firstChild = firstChild;
    node->nextSibling = nextSibling;
    return node;
}

Tree *tree_new()
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->size = 0;
    tree->root = NULL;
    return tree;
}

void tree_list(Tree *tree, Element *elements)
{
    tree_preorder(tree->root, elements);
}

void tree_preorder(TreeNode *node, Element *elements)
{
    if (node)
    {
        elements = node->e;
        elements++;
        tree_preorder(node->firstChild, elements);
        tree_preorder(node->nextSibling, elements);
    }
    return;
}

// return the result of postorder
void tree_postorder(TreeNode *node, Element *elements)
{
    if (node)
    {
        tree_postorder(node->firstChild, elements);
        tree_postorder(node->nextSibling, elements);
        elements = node->e;
        elements++;
    }
    return;
}

// return the result of level order
void tree_levelorder(TreeNode *node, Element *elements)
{
    if (node)
    {
        LinkedQueue *queue = linked_queue_new();
        en_queue(node, queue);
        while (!is_empty(queue))
        {
            TreeNode *temp = de_queue(queue);
            elements = temp->e;
            elements++;
            TreeNode *child = temp->firstChild;
            while (child)
            {
                en_queue(child, queue);
                child = child->nextSibling;
            }
        }
    }
    return;
}
