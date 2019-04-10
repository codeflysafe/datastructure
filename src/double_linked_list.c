/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-10 19:21:31
 * @LastEditTime: 2019-04-10 22:03:39
 */

#include "include/double_linked_list.h"
#include <stdlib.h>

DoubleLinkedNode *double_linked_node_new(Element e, DoubleLinkedNode *prev, DoubleLinkedNode *next)
{
    DoubleLinkedNode *node;
    node = (DoubleLinkedNode *)malloc(sizeof(DoubleLinkedNode));
    node->element = e;
    node->prev = prev;
    node->next = next;
    if (prev)
    {
        prev->next = node;
    }
    if (next)
    {
        next->prev = node;
    }

    return node;
}

DoubleLinkedList *double_linked_list_new()
{
    DoubleLinkedList *list;
    list = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    DoubleLinkedNode *head = double_linked_node_new(NULL, NULL, NULL);
    DoubleLinkedNode *tail = double_linked_node_new(NULL, head, NULL);
    list->tail = tail;
    list->head = head;
    list->length = 0;
    return list;
}
// return the current length
int len(DoubleLinkedList *list)
{
    return list->length;
}

// return true if the list is empty or false if not
boolean is_empty(DoubleLinkedList *list)
{
    return list->length == 0 ? 1 : 0;
}

// return the index of e or -1 if not exists
int index_of_list(Element e, DoubleLinkedList *list, compare_func cmp)
{
    if (is_empty(list))
    {
        return -1;
    }
    int index = 0;
    DoubleLinkedNode *node = list->head->next;
    while (node)
    {
        if (cmp(node->element, e) == 0)
        {
            return index;
        }
        node = node->next;
        index++;
    }
    return -1;
}

DoubleLinkedNode *node_of_list(Element e, DoubleLinkedList *list, compare_func cmp)
{
    if (is_empty(list))
    {
        return NULL;
    }
    DoubleLinkedNode *node = list->head->next;
    while (node)
    {
        if (cmp(node->element, e) == 0)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

// return the element whose index is index
Element find(unsigned int index, DoubleLinkedList *list)
{
    DoubleLinkedNode *node = find_node(index, list);
    return node != NULL ? node->element : NULL;
}

DoubleLinkedNode *find_node(unsigned int index, DoubleLinkedList *list)
{
    if (index > list->length)
    {
        return NULL;
    }

    if (index <= list->length / 2)
    {
        int i = 0;
        DoubleLinkedNode *node = list->head->next;
        while (i < index)
        {
            node = node->next;
            i++;
        }
        return node;
    }
    else
    {
        int i = 0;
        DoubleLinkedNode *node = list->tail->next;
        while (i < (list->length - index))
        {
            node = node->prev;
            i++;
        }
        return node;
    }
}

// delete the element in array;
void delete_one(unsigned int index, DoubleLinkedList *list)
{
    if (index > list->length)
    {
        return;
    }
    if (index <= list->length / 2)
    {
        int i = -1;
        DoubleLinkedNode *node = list->head;
        while (i < index - 1)
        {
            node = node->next;
            i++;
        }
        DoubleLinkedNode *tmp = node->next;
        node->next = tmp->next;
        tmp->next->prev = node;
        tmp->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }
    else
    {
        int i = 0;
        DoubleLinkedNode *node = list->tail->next;
        while (i < (list->length - index))
        {
            node = node->prev;
        }
        DoubleLinkedNode *tmp = node->prev;
        node->prev = tmp->prev;
        tmp->prev->next = node;
        tmp->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }
}

// delete the element in array;
void delete_value(Element e, DoubleLinkedList *list, compare_func cmp)
{
    DoubleLinkedNode *node = node_of_list(e, list, cmp);
    if (node)
    {
        DoubleLinkedNode *prev = node->prev;
        DoubleLinkedNode *next = node->next;
        prev->next = next;
        next->prev = prev;
        next->prev = NULL;
        next->next = NULL;
        free(next);
    }
}

// insert the element in array; always in tail;
void push_back(Element e, DoubleLinkedList *list)
{
    DoubleLinkedNode *tail = list->tail;
    DoubleLinkedNode *prev = tail->prev;
    double_linked_node_new(e, prev, tail);
}

//  insert the element in array; always in front;
void push_front(Element e, DoubleLinkedList *list)
{
    DoubleLinkedNode *head = list->head;
    DoubleLinkedNode *next = head->next;
    double_linked_node_new(e, head, next);
    list->length++;
}

//  insert the element in array;
void push_index(Element e, unsigned int index, DoubleLinkedList *list)
{
    DoubleLinkedNode *node = find_node(index, list);
    if (node)
    {
        DoubleLinkedNode *prev = node->prev;
        double_linked_node_new(e, prev, node);
        list->length++;
    }
}

// clear data and release the space ;
void clear(DoubleLinkedList *list)
{
    DoubleLinkedNode *root = list->head;
    while (root)
    {
        root->element = NULL;
        root->prev = NULL;
        DoubleLinkedNode *node = root->next;
        root->next = NULL;
        free(root);
        root = node;
    }
    list->length = 0;
    free(list);
}

// reverse the array
void reverse(DoubleLinkedList *list)
{
    // todo
}
