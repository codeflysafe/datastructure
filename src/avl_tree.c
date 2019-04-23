/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-23 21:32:28
 * @LastEditTime: 2019-04-23 23:07:02
 */

#include "include/avl_tree.h"
#include <stdlib.h>

struct AvlNode
{
    Element e;
    int rate; // 频率
    struct AvlNode *left;
    struct AvlNode *right;
    int height;
};

AvlTree make_empty(AvlTree t)
{
    if (t)
    {
        make_empty(t->left);
        make_empty(t->right);
        free(t);
    }
    return NULL;
}

Position single_rotate_with_left(Position k2)
{
    Position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}

Position single_rotate_with_right(Position k1)
{
    Position k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k2;
}

Position rotate_with_right_left(Position k3)
{
    k3->left = single_rotate_with_right(k3->left);
    return single_rotate_with_left(k3);
}

Position rotate_with_left_right(Position k1)
{
    k1->right = single_rotate_with_left(k1->right);
    return single_rotate_with_right(k1);
}

AvlTree insert(Element e, AvlTree t, compare_func cmp)
{
    if (t == NULL)
    {
        t = (AvlTree)malloc(sizeof(struct AvlNode));
        t->height = 0;
        t->e = e;
        return t;
    }
    int cp = cmp(e, t->e);
    if (cp == 0)
    {
        t->rate = 1;
        return t;
    }
    else if (cp > 0)
    {
        t->right = insert(e, t->right, cmp);
        if (height(t->right) - height(t->left) == 2)
        {
            if (cmp(e, t->right->e) > 0)
            {
                t = single_rotate_with_right(t);
            }
            else
            {
                t = rotate_with_right_left(t);
            }
        }
    }
    else
    {
        t->left = insert(e, t->left, cmp);
        if (height(t->left) - height(t->right) == 2)
        {
            if (cmp(e, t->left->e) < 0)
            {
                t = single_rotate_with_left(t);
            }
            else
            {
                t = rotate_with_left_right(t);
            }
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

AvlTree remove(Element e, AvlTree t, compare_func cmp)
{
    Position p = find(e, t, cmp);
    if (p == NULL)
    {
        return NULL;
    }
    p->rate = 0;
    return p;
}

Position find(Element e, AvlTree t, compare_func cmp)
{
    if (t == NULL)
    {
        return NULL;
    }
    int cp = cmp(e, t->e);
    if (cp == 0)
    {
        return t->rate > 0 ? t->e : NULL;
    }
    else if (cp > 0)
    {
        return find(e, t->right, cmp);
    }
    else
    {
        return find(e, t->left, cmp);
    }
}

Position find_min(AvlTree t)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->left == NULL)
    {
        return t;
    }
    else
    {
        return find_min(t->left);
    }
}

AvlTree find_max(AvlTree t)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->right == NULL)
    {
        return t;
    }
    else
    {
        return find_max(t->right);
    }
}

int height(Position t)
{
    return t == NULL ? 0 : t->height;
}
