/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-26 18:27:39
 * @LastEditTime: 2019-05-06 12:06:24
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



