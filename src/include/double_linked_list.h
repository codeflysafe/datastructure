/**
 * @description: double linked list 
 * @notice: 
 * @param {type} 
 * @return: 
 */

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include "common.h"

typedef struct double_linked_node
{
    Element *element;
    struct double_linked_node *prev;
    struct double_linked_node *next;

} DoubleLinkedNode;

// create a node 
DoubleLinkedNode *double_linked_node_new();

typedef struct double_linked_list
{
    DoubleLinkedNode *tail; // tail node
    DoubleLinkedNode *head; // head node
    int length;             // the length of this list

} DoubleLinkedList;



#endif
