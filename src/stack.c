/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 14:42:27
 * @LastEditTime: 2019-04-12 10:36:43
 */

#include "include/stack.h"
#include <stdlib.h>
#include <string.h>

StackNode *stack_node_new(Element e, StackNode *next)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->e = e;
    node->next = next;
    return node;
}

void free_node(StackNode *node)
{
    if (node)
    {
        node->e = NULL;
        node->next = NULL;
        free(node);
    }
}

Stack *stack_new()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->length = 0;
    return stack;
}

// delete the top of stack,meanwhile return it;
Element pop(Stack *stack)
{
    if (is_empty(stack))
    {
        return NULL;
    }
    StackNode *node = stack->head;
    stack->head = node->next;
    stack->length--;
    Element e = node->e;
    free_node(node);
    return e;
}

// get the top element of stack;
Element top(Stack *stack)
{
    if (is_empty(stack))
    {
        return NULL;
    }
    return stack->head->e;
}

// push element to stack;
void push(Element e, Stack *stack)
{
    StackNode *node = stack_node_new(e, stack->head);
    stack->head = node;
    stack->length++;
}

// check the stack is empty or not;
boolean is_empty(Stack *stack)
{
    return stack->length == 0 ? 1 : 0;
}

// clear the stack as an empty;
void clear(Stack *stack)
{
    StackNode *root = stack->head;
    while (root)
    {
        StackNode *tmp = root->next;
        free_node(root);
        root = tmp;
    }
    stack->length = 0;
}

// destory the stack
void destory(Stack *stack)
{
    clear(stack);
    free(stack);
}
