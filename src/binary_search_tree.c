/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-22 12:33:40
 * @LastEditTime: 2019-04-23 09:44:57
 */

#include "include/binary_search_tree.h"
#include <stdlib.h>

// binary_search_tree_node is the node of binary tree
// contains the left child and right child node
struct binary_search_tree_node
{
    struct binary_search_tree_node *left;
    struct binary_search_tree_node *right;
    Element val;
};

TreeNode *tree_node_new(Element e, SearchTree left, SearchTree right)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    return node;
}

// recursive make node empty
SearchTree
make_empty(SearchTree t)
{
    if (t)
    {
        make_empty(t->left);
        make_empty(t->right);
        free(t);
    }
    return NULL;
}

// recursive search node
Position find(Element e, SearchTree t, compare_func cmp)
{
    if (t)
    {
        int cp = cmp(t->val, e);
        if (cp == 0)
            return t;
        else if (cp > 0)
            return find(e, t->left, cmp);
        else
            return find(e, t->right, cmp);
    }
    return NULL;
}

// the mininum value in tree the left leaf
Position find_min(SearchTree t)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->left == NULL)
    {
        return t;
    }
    else
    {
        return find_min(t->left);
    }
}

Position find_max(SearchTree t)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->right == NULL)
    {
        return t;
    }
    else
    {
        return find_max(t->right);
    }
}

// recursive insert
SearchTree insert(Element e, SearchTree t, compare_func cmp)
{
    if (t == NULL)
    {
        t = tree_node_new(e, NULL, NULL);
        return t;
    }
    int cp = cmp(e, t->val);
    if (cp == 0)
        return t;
    else if (cp < 0)
        t->left = insert(e, t->left, cmp);
    else
        t->right = insert(e, t->right, cmp);
    return t;
}

SearchTree remove(Element e, SearchTree t, compare_func cmp)
{
    SearchTree node = find(e, t, cmp);
    if (node)
    {
        if (node->left != NULL && node->right != NULL)
        {
            SearchTree mini = find_min(node->right);
            node->val = mini->val;
            node->right = remove(mini->val, node->right, cmp);
        }
        else
        {
            if (node->left != NULL)
            {
                node = node->left;
            }
            else if (node->right != NULL)
            {
                node = node->right;
            }
            free(node);
        }
    }
    return node;
}
