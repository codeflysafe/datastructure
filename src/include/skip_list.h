/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-17 16:29:33
 * @LastEditTime: 2019-04-18 14:31:57
 */
#ifndef SKIP_LIST
#define SKIP_LIST

#include "common.h"

typedef struct skip_list_node
{
    // the value
    Element e;
    // the backward in the same level
    struct skip_list_node *backward;
    struct skip_list_level
    {
        // the next node in the same level
        struct skip_list_node *forward;
    } level[];

} SkipListNode;

SkipListNode *skip_list_node_new(Element e, int level);

typedef struct skip_list
{
    SkipListNode *header, *tail;
    // the size stored in this list
    unsigned int size;
    // the current maxt level
    int level;
} SkipList;

SkipList *skip_list_new();

SkipListNode *skip_list_search(SkipList *list, Element e, compare_func cmp);

Element *skip_list_find(SkipList *list, Element e, compare_func cmp);

void skip_list_insert(SkipList *list, Element e, compare_func cmp);

void skip_list_delete(SkipList *list, Element e, compare_func cmp);

int random_level();

#endif
