/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 14:47:41
 * @LastEditTime: 2019-05-06 20:50:38
 */

#include "include/queue.h"
#include <stdlib.h>

QNode *q_node_new(Element e, QNode *next)
{
    QNode *node = (QNode *)malloc(sizeof(QNode));

    if (node)
    {
        node->data = e;
        node->next = next;
    }
    return node;
}

LinkedQueue *linked_queue_new()
{
    LinkedQueue *queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if (queue)
    {
        queue->front = queue->rear = q_node_new(NULL, NULL);
        queue->size = 0;
    }
    return queue;
}

void en_queue(Element e, LinkedQueue *queue)
{
    QNode *node = q_node_new(e, NULL);
    if (queue->size == 0)
    {
        queue->front->next = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

Element de_queue(LinkedQueue *queue)
{
    if (queue->size == 0)
        return NULL;
    QNode *node = queue->front->next;
    queue->front = node->next;
    Element e = node->data;
    if ((queue->rear) == node)
        queue->rear = queue->front;
    free(node);
    queue->size--;
    return e;
}

void clear_queue(LinkedQueue *queue)
{
    QNode *node = queue->front;
    while (node)
    {
        node->data = NULL;
        node->next = NULL;
        QNode *temp = node->next;
        free(node);
        node = temp;
    }
    queue->size = 0;
}

void destory_queue(LinkedQueue *queue)
{
    clear_queue(queue);
    free(queue);
}

CircleQueue *circle_queue_new(int capacity)
{
    if (capacity > MAX_QUEUE_SIZE)
    {
        return NULL;
    }
    CircleQueue *queue = (CircleQueue *)malloc(sizeof(CircleQueue));
    if (queue == NULL)
        return NULL;
    queue->elements =malloc(capacity * sizeof(Element));
    if (queue->elements == NULL)
        return NULL;
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

void en_circle_queue(Element e, CircleQueue *queue)
{
    if (is_full(queue))
        return;
    queue->elements[queue->rear] = e;
    queue->rear = (queue->rear + 1) % queue->capacity;
}

Element de_circle_queue(CircleQueue *queue)
{
    if (len(queue) == 0)
        return NULL;
    Element e = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return e;
}

int len(CircleQueue *queue)
{
    return (queue->rear - queue->front + queue->capacity) % queue->capacity;
}

boolean is_full(CircleQueue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front ? 1 : 0;
}

void clear_circle_queue(CircleQueue *queue)
{
    queue->front = queue->rear = 0;
}

void destory_circle_queue(CircleQueue *queue)
{
    clear_circle_queue(queue);
    free(queue->elements);
    free(queue);
}
