/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-24 13:07:51
 * @LastEditTime: 2019-04-26 08:31:52
 */

#include "include/b_tree.h"
#include <stdlib.h>

struct BTreeNode
{
    int num;                      // the value num in this node
    struct BTreeNode *ptr[M + 1]; // the ptr collection + 1 . the true value start from 1 --- M +1 (left node)
    Element *elements[M + 1];     // the value collection + 1;i-1 from 0 - M+1
    boolean isLeaf;               // is leaf or not
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
