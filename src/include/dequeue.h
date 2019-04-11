/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 14:57:07
 * @LastEditTime: 2019-04-11 15:00:45
 */

#ifndef DEQUEUE
#define DEQUEUE
#include "double_linked_list.h"

typedef struct dequeue{
    DoubleLinkedList *data;
} Dequeue;


Dequeue *dequeue_new();


#endif
