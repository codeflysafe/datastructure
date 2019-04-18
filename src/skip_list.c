/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-18 12:32:58
 * @LastEditTime: 2019-04-18 18:50:02
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
    int level = list->level;
    SkipListNode *head = list->header;
    while (head && level >= 0)
    {
        SkipListNode *temp = head->level[level].forward;
        if (temp == NULL)
            level--;
        else
        {
            int p = cmp(temp->e, e);
            if (p == 0)
                return temp;
            else if (p < 0)
                head = temp;
            else
                level--;
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
    SkipListNode *update[MAX_SKIP_LIST_LEVEL], *x;
    SkipListNode *head = list->header;
    int i, level;
    for (i = list->level; i >= 0; i--)
    {
        SkipListNode *temp = head->level[i].forward;
        if (temp)
        {
            int p = cmp(temp->e, e);
            // has exists return
            if (p == 0)
                return;
            // if the value less target;node forward
            // meantime,the left node update
            else if (p < 0)
            {
                head = temp;
            }
            // if the value greater target; update the right node
            //  else  continue;
        }
        update[i] = head;
    }

    // start modify the list
    // meantime update the
    level = random_level();
    if (level > list->level)
    {
        for (i = list->level; i < level; i++)
        {
            update[i] = list->header;
        }
        list->level = level;
    }

    x = skip_list_node_new(e, level);
    for (i = 0; i < level; i++)
    {
        x->level[i].forward = update[i]->level[i].forward;
        update[i]->level[i].forward = x;
    }

    x->backward = (update[0] == list->header) ? NULL : update[0];
    if (x->level[0].forward)
    {
        x->level[0].forward->backward = x;
    }
    else
    {
        list->tail = x;
    }
    list->size++;
    return;
}

//
int random_level()
{
    int level = 0;
    while ((random() & 0xFFFF) < (SKIP_LIST_P * 0xFFFF))
    {
        level++;
    }
    return level < MAX_SKIP_LIST_LEVEL ? level : MAX_SKIP_LIST_LEVEL;
}

// delete an element from list
void skip_list_delete(SkipList *list, Element e, compare_func cmp)
{
    SkipListNode *update[MAX_SKIP_LIST_LEVEL], *x;
    x = list->header;
    int i, level;
    for (i = list->level; i >= 0; i--)
    {
        while (x->level[i].forward && cmp(x->level[i].forward->e, e) < 0)
        {
            x = x->level[i].forward;
        }
        update[i] = x;
    }

    x = x->level[0].forward;
    if (x && cmp(x->backward, e) == 0)
    {
        skip_list_delete_node(list, x, update);
    }
}

void skip_list_delete_node(SkipList *list, SkipListNode *node, SkipListNode **update)
{
    int i;
    for (i = 0; i < list->level; i++)
    {
        if (update[i]->level[i].forward == node)
        {
            update[i]->level[i].forward = node->level[i].forward;
        }
    }
    if (node->level[0].forward)
    {
        node->level[0].forward->backward = node->backward;
    }
    else
    {
        list->tail = node->backward;
    }
    while (list->level > 0 && list->header->level[list->level].forward == NULL)
    {
        list->level--;
    }
    list->size--;
}
