/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 14:47:41
 * @LastEditTime: 2019-04-11 14:56:26
 */

#ifndef QUEUE
#define QUEUE
#include "double_linked_list.h"

typedef struct queue
{
    DoubleLinkedList *data;
} Queue;

Queue *queue_new();

void en_queue(Element e, Queue *queue);

boolean is_empty(Queue *queue);

Element de_queue(Queue *queue);

#endif
