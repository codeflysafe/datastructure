/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-24 13:07:51
 * @LastEditTime: 2019-04-26 17:35:48
 */

#include "include/b_tree.h"
#include <stdlib.h>

struct BTreeNode
{
    int num;                  // the value num in this node
    struct BTreeNode *ptr[M]; // the point to child node
    Element *elements[M];     // the num of keywords [M/2] =< range  < =M
    boolean isLeaf;           // is leaf or not. the ptr is empty array when the node  is leaf,
};

// Recursive make the tree to empty
// clear the b tree
BTree make_empty(BTree t)
{
    if (t != NULL)
    {
        for (int i = 0; i < t->num; i++)
        {
            make_empty(t->ptr[i]);
        }
        free(t);
    }
    return NULL;
}

// find the key
Position find(Element e, BTree t, compare_func cmp)
{
    if (t != NULL)
    {
        int i = 0;
        while (i < t->num)
        {
            int cp = cmp(e, t->elements[i]);
            if (cp == 0)
                return t;
            else if (cp > 0 && !t->isLeaf)
            {
                return find(e, t->ptr[i], cmp);
            }
            i++;    
        }
    }
    return NULL;
}


Position find_min(BTree t)
{
}
Position find_max(BTree t)
{
}
BTree insert(Element e, BTree t, compare_func cmp)
{
}
BTree remove(Element e, BTree t, compare_func cmp)
{
}
