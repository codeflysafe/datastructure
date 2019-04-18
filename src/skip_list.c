/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-18 12:32:58
 * @LastEditTime: 2019-04-18 14:32:01
 */
#include <stdlib.h>
#include "include/skip_list.h"

SkipListNode *skip_list_node_new(Element e, int level)
{
    SkipListNode *node = (SkipListNode *)malloc(
        sizeof(*node) + level * sizeof(struct skip_list_level));
    node->e = e;
    return node;
}

SkipList *skip_list_new()
{
    SkipList *list = (SkipList *)malloc(sizeof(SkipList));
    list->size = 0;
    list->level = 0;
    list->header = skip_list_node_new(NULL, MAX_SKIP_LIST_LEVEL);
    for (int i = 0; i < MAX_SKIP_LIST_LEVEL; i++)
    {
        list->header->level[i].forward = NULL;
    }
    list->tail = NULL;
    return list;
}

SkipListNode *skip_list_search(SkipList *list, Element e, compare_func cmp)
{
    if (list->size == 0)
        return NULL;
    int level = list->level;
    SkipListNode *head = list->header;
    while (head && level >= 0)
    {
        SkipListNode *temp = head->level[level].forward;
        if (temp == NULL)
        {
            level--;
        }
        else
        {
            int p = cmp(temp->e, e);
            if (p == 0)
            {
                return temp;
            }
            else if (p < 0)
            {
                head = temp;
            }
            else
            {
                level--;
            }
        }
    }
    return NULL;
}

Element *skip_list_find(SkipList *list, Element e, compare_func cmp)
{
    SkipListNode *temp = skip_list_search(list, e, cmp);
    return temp == NULL ? NULL : temp->e;
}

void skip_list_insert(SkipList *list, Element e, compare_func cmp)
{
    
}
