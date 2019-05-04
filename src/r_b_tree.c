/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-26 18:27:39
 * @LastEditTime: 2019-04-26 19:34:54
 */

#include "include/r_b_tree.h"
#include <stdlib.h>

struct r_b_node
{
    struct r_b_node *parent;
    struct r_b_node *left;
    struct r_b_node *right;
    Element val;
    enum Color color; // RED or BLACK
};
