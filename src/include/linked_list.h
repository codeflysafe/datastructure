/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:21:09
 * @LastEditTime: 2019-04-10 21:49:53
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
} LinkedNode;

/**
 * @description: generate an Node 
 * @param {type} 
 * @return: 
 */
LinkedNode *linked_node_new(Element e, LinkedNode *next);

typedef struct linked_list
{
    LinkedNode *root; // root node
    int length;       // the size of linked list

} LinkedList;

// create linked list
LinkedList *linked_list_new();

// return the current length
int len(LinkedList *list);

// return true if the list is empty or false if not
boolean is_empty(LinkedList *list);

// return the index of e or -1 if not exists
int index_of_list(Element e, LinkedList *list, compare_func cmp);

// return the element whose index is index
Element find(unsigned int index, LinkedList *list);

// delete the element in array;
void delete_one(unsigned int index, LinkedList *list);

// delete the element in array;
void delete_value(Element e, LinkedList *list, compare_func cmp);

// insert the element in array; always in tail;
void push_back(Element e, LinkedList *list);

//  insert the element in array; always in front;
void push_front(Element e, LinkedList *list);

//  insert the element in array;
void push_index(Element e, unsigned int index, LinkedList *list);

// clear data and release the space ;
void clear(LinkedList *list);

// reverse the array
void reverse(LinkedList *list);

// /**
//  * @description:
//  * @param {type}
//  * @return:
//  */
// void q_sort(LinkedList *list, unsigned int left, unsigned int right, boolean desc, compare_func cmp);

// /**
//  * @description: sort the array; desc or asc
//  * @param {type}
//  * @return:
//  */
// void sort(LinkedList *list, boolean desc, compare_func cmp);

#endif //DATA_STRUCTURE_LINKEDLIST_H
