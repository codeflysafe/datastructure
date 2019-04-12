/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 14:42:19
 * @LastEditTime: 2019-04-12 10:17:06
 */

#ifndef STACK
#define STACk
#include "common.h"

typedef struct stack_node
{
    Element e;
    struct stack_node *next;

} StackNode;

StackNode *stack_node_new(Element e, StackNode *next);

void free_node(StackNode *node);

typedef struct stack
{
    StackNode *head;
    int length;

} Stack;

// create an empty stack
Stack *stack_new();

// delete the top of stack,meanwhile return it;
Element pop(Stack *stack);

// get the top element of stack;
Element top(Stack *stack);

// push element to stack;
void push(Element e, Stack *stack);

// check the stack is empty or not;
boolean is_empty(Stack *stack);

// clear the stack as an empty;
void clear(Stack *stack);

// destory the stack
void destory(Stack *stack);

#endif
