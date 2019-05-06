/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-26 08:52:40
 * @LastEditTime: 2019-05-06 12:06:03
 */

#ifndef R_B_TREE
#define R_B_TREE
#include "common.h"

enum color
{
    RED,
    BLACk,
};

// define the color 
typedef enum color Color;

struct r_b_node;
// define the rb tree node
typedef struct r_b_node *RBTreeNode, *RBTree;

#endif
