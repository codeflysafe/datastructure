/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:22:00
 * @LastEditTime: 2019-04-10 11:14:39
 */

#include "include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// create an linked node
LinkedNode *linked_node_new(Element e, LinkedNode *next)
{
    LinkedNode *node;
    node = (LinkedNode *)malloc(sizeof(LinkedNode));
    node->e = e;
    node->next = next;
    return node;
}

LinkedList *linked_list_new()
{
    LinkedList *list;
    list = (LinkedList *)malloc(sizeof(LinkedList));
    list->length = 0;
    list->root = linked_node_new(NULL, NULL);
    return list;
}

// return the current length
int len(LinkedList *list)
{
    return list->length;
}

// return true if the list is empty or false if not
boolean is_empty(LinkedList *list)
{
    return list->length == 0 ? 1 : 0;
}

// return the index of e or -1 if not exists
int index_of_list(Element e, LinkedList *list, compare_func cmp)
{
    if (is_empty(list))
    {
        return -1;
    }
    int index = 0;
    LinkedNode *node = list->root->next;
    while (node != NULL)
    {
        if (cmp(node->e, e) == 0)
        {
            return index;
        }
        else
        {
            index++;
            node = node->next;
        }
    }
    return -1;
}

// return the element whose index is index or return Null if not found
Element find(unsigned int index, LinkedList *list)
{
    if (index < 0 || index >= list->length)
    {
        return NULL;
    }

    int i = 0;
    LinkedNode *node = list->root->next;
    while (i < index)
    {
        node = node->next;
        i++;
    }
    return node->e;
}

// delete the element in array;
void delete_one(unsigned int index, LinkedList *list)
{
    if (index < 0 || index >= list->length)
    {
        return;
    }

    LinkedNode *root = list->root;
    int i = -1;
    while (i < index - 1)
    {
        root = root->next;
        i++;
    }
    LinkedNode *node = root->next;
    root->next = node->next;
    free(node); // release the delete node
}

// delete the element in array;
void delete_value(Element e, LinkedList *list, compare_func cmp)
{
    if (is_empty(list))
    {
        return;
    }
    LinkedNode *root = list->root;
    while (root->next != NULL)
    {
        if (cmp(root->next->e, e) == 0)
        {
            LinkedNode *node = root->next;
            root->next = node->next;
            free(node);
            return;
        }
        else
        {
            root = root->next;
        }
    }
}

// insert the element in array; always in tail;
void push_back(Element e, LinkedList *list)
{
    push_index(e, len(list), list);
}

//  insert the element in array; always in front;
void push_front(Element e, LinkedList *list)
{
    push_index(e, 0, list);
}

//  insert the element in array;
void push_index(Element e, unsigned int index, LinkedList *list)
{

    if (index > list->length)
    {
        return;
    }
    LinkedNode *head = list->root;
    int i = 0;
    while (i < index)
    {
        head = head->next;
        i++;
    }
    LinkedNode *node = linked_node_new(e, head->next);
    head->next = node;
}

// clear data and release the space ;
void clear(LinkedList *list)
{
    if (is_empty(list))
    {
        free(list->root);
        list->root = NULL;
        list->length = 0;
        free(list);
        return;
    }

    LinkedNode *root = list->root;
    while (root)
    {
        root->e = NULL;
        LinkedNode *node = root->next;
        root->next = NULL;
        free(root);
        root = node;
    }
    list->length = 0;
    free(list);
}

// reverse the array
void reverse(LinkedList *list)
{
    if (list->length <= 1)
    {
        return;
    }

    LinkedNode *root = list->root;
    LinkedNode *first = root->next;
    LinkedNode *node = first->next;
    while (node)
    {
        LinkedList *tmp = node->next;
        node->next = first;
        first->next = tmp;
        root->next = node;
        first = node;
        node = tmp;
    }
}

void q_sort(LinkedList *list, unsigned int left, unsigned int right, boolean desc, compare_func cmp)
{
   
}

void sort(LinkedList *list, boolean desc, compare_func cmp)
{
   
}
