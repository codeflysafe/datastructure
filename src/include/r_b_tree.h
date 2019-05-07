/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-26 08:52:40
 * @LastEditTime: 2019-05-07 12:50:22
 */

#ifndef R_B_TREE
#define R_B_TREE
#include "common.h"

enum color
{
    RED,
    BLACK,
};

// define the color
typedef enum color Color;

struct r_b_node;
// define the rb tree node
typedef struct r_b_node *RBTreeNode;

RBTreeNode make_node(Element e);

struct r_b_tree;

typedef struct r_b_tree *RBTree;

// RBTree make_empty(RBTree t);

void re_color(RBTreeNode a);

void right_rotation(RBTree t, RBTreeNode a);

void left_rotation(RBTree t, RBTreeNode a);

void insert(RBTree t, Element e, compare_func cmp);

void insert_fix_up(RBTree t, RBTreeNode n);

void delete (RBTree t, Element e, compare_func cmp);

void delete_fix_up(RBTree t, RBTreeNode n);

#endif
