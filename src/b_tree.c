/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-24 13:07:51
 * @LastEditTime: 2019-04-25 08:18:13
 */

#include "include/b_tree.h"
#include <stdlib.h>

struct BTreeNode
{
    int num; // the value num in this node
    struct BTreeNode *ptr[M+1]; // the ptr collection + 1 
    Element *elements[M+1]; // the value collection + 1 
};

