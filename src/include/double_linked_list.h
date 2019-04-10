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
DoubleLinkedNode *double_linked_node_new(Element e, DoubleLinkedNode *prev, DoubleLinkedNode *next);

typedef struct double_linked_list
{
    DoubleLinkedNode *tail; // tail node
    DoubleLinkedNode *head; // head node
    int length;             // the length of this list

} DoubleLinkedList;

DoubleLinkedList *double_linked_list_new();

// return the current length
int len(DoubleLinkedList *list);

// return true if the list is empty or false if not
boolean is_empty(DoubleLinkedList *list);

// return the index of e or -1 if not exists
int index_of_list(Element e, DoubleLinkedList *list, compare_func cmp);

// return the element whose index is index
Element find(unsigned int index, DoubleLinkedList *list);

DoubleLinkedNode *find_node(unsigned int index, DoubleLinkedList *list);

// delete the element in array;
void delete_one(unsigned int index, DoubleLinkedList *list);

// delete the element in array;
void delete_value(Element e, DoubleLinkedList *list, compare_func cmp);

// insert the element in array; always in tail;
void push_back(Element e, DoubleLinkedList *list);

//  insert the element in array; always in front;
void push_front(Element e, DoubleLinkedList *list);

//  insert the element in array;
void push_index(Element e, unsigned int index, DoubleLinkedList *list);

// clear data and release the space ;
void clear(DoubleLinkedList *list);

// reverse the array
void reverse(DoubleLinkedList *list);

#endif
