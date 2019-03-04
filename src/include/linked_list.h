/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:21:09
 * @LastEditTime: 2019-03-04 10:40:05
 */

#ifndef DATA_STRUCTURE_LINKEDLIST_H
#define DATA_STRUCTURE_LINKEDLIST_H
#include "common.h"


/**
 * @description: the node of the linked list
 * @param {type} 
 * @return: 
 */
typedef struct linked_node
{
    Element e;                // the value
    struct linked_node *next; // next node
    struct linked_node *prev; // prev node

} Node;


/**
 * @description: generate an Node 
 * @param {type} 
 * @return: 
 */
Node *node_new(Element e);

typedef struct linked_list
{
    Node *head; // head node
    Node *tail; // tail node
    int length; // the size of linked list

} LinkedList;

LinkedList *linked_list_new()
{

}

#endif //DATA_STRUCTURE_LINKEDLIST_H
