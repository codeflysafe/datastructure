/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-26 18:27:39
 * @LastEditTime: 2019-05-06 23:12:18
 */

#include "include/r_b_tree.h"
#include <stdlib.h>

// red and black tree
struct r_b_node
{
    struct r_b_node *parent;
    struct r_b_node *left;
    struct r_b_node *right;
    Element val;
    Color color; // RED or BLACK
};

RBTreeNode make_node(Element e)
{
    RBTreeNode n = (RBTreeNode)malloc(sizeof(RBTreeNode));
    n->val = e;
    return n;
}

struct r_b_tree
{
    RBTreeNode root;
    RBTreeNode nil;
};

// re color  and the conflict node grandParent
void re_color(RBTreeNode b)
{
    b->parent->color = RED;
    b->parent->left->color = BLACK;
    b->parent->right->color = BLACK;
    return;
}

// right rotation
void right_rotation(RBTree t, RBTreeNode b)
{
    RBTreeNode a = b->left;
    b->left = a->right;
    if (a->right != NULL)
    {
        a->right->parent = b;
    }
    a->parent = b->parent;
    if (b->parent == NULL)
    {
        t->root = a;
    }
    else if (b == b->parent->left)
    {
        b->parent->left = a;
    }else{
        b->parent->right = a;
    }
    a->right = b;
    b->parent = a;
}

void left_rotation(RBTree t, RBTreeNode a)
{
    RBTreeNode b = a->right;
    a->right = b->left;
    if (a->left != NULL)
    {
        b->left->parent = a;
    }
    b->parent = a->parent;
    if (a->parent == NULL)
    {
        t->root = b;
    }
    else if (a == b->parent->left)
    {
        a->parent->left = b;
    }
    else
    {
        a->parent->right = b;
    }

    b->left = a;
    a->parent = b;
}

void insert(RBTree t, Element e, compare_func cmp)
{
    RBTreeNode root = t->root;
    RBTreeNode temp = t->nil;
    while (root != t->nil)
    {
        temp = root;
        if (cmp(e, root->val) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    RBTreeNode n = make_node(e);
    n->parent = temp;
    if (temp == t->nil)
    {
        t->root = n;
    }
    else if (cmp(e, temp->val) < 0)
    {
        temp->left = n;
    }
    else
    {
        temp->right = n;
    }
    n->left = t->nil;
    n->right = t->nil;
    n->color = RED;
    insert_fix_up(t, n);
    return;
}

void insert_fix_up(RBTree t, RBTreeNode n)
{
    while (n->parent->color == RED)
    {
        // left child subtree
        if (n->parent == n->parent->parent->left)
        {

            RBTreeNode y = n->parent->parent->right;
            // case-1
            if (y->color == RED)
            {
                re_color(n->parent);
                n = n->parent->parent;
            }
            // case 2
            else if (n == n->parent->right)
            {
                n = n->parent;
                left_rotation(t, n);
            }
            // case 3
            else
            {
                n->parent->color = BLACK;
                n->parent->parent->color = RED;
                right_rotation(t, n->parent->parent);
            }
        }
        // right subtree
        else
        {
            RBTreeNode y = n->parent->parent->left;
            // case-1
            if (y->color == RED)
            {
                re_color(n->parent);
                n = n->parent->parent;
            }
            // case 2
            else if (n == n->parent->left)
            {
                n = n->parent;
                right_rotation(t, n);
            }
            // case 3
            else
            {
                n->parent->color = BLACK;
                n->parent->parent->color = RED;
                left_rotation(t, n->parent->parent);
            }
        }
    }

    t->root->color = BLACK;
}
