/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 14:47:41
 * @LastEditTime: 2019-04-17 09:37:41
 */

#ifndef QUEUE
#define QUEUE
#include "common.h"

// define the linked queue
typedef struct q_node
{
    Element data;
    struct q_node *next;

} QNode;

QNode *q_node_new(Element data, QNode *next);

typedef struct linked_queue
{
    int size;
    QNode *front; // the pointer to queue's front
    QNode *rear;  //  the pointer to queue's rear
} LinkedQueue;

LinkedQueue *linked_queue_new();

void en_queue(Element e, LinkedQueue *queue);

boolean is_empty(LinkedQueue *queue);

Element de_queue(LinkedQueue *queue);

void clear_queue(LinkedQueue *queue);

void destory_queue(LinkedQueue *queue);

// the circle queue

typedef struct circle_queue
{
    Element *elements;
    int capacity;
    int front; // the  pointer of front
    int rear;  // the
} CircleQueue;

CircleQueue *circle_queue_new(int capacity);

void en_circle_queue(Element e, CircleQueue *queue);

// return current elements's size of queue
int len(CircleQueue *queue);

boolean is_full(CircleQueue *queue);

Element
de_circle_queue(CircleQueue *queue);

void clear_circle_queue(CircleQueue *queue);

void destory_circle_queue(CircleQueue *queue);

#endif
