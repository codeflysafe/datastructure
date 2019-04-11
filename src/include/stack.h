/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-11 14:42:19
 * @LastEditTime: 2019-04-11 14:53:08
 */

#ifndef STACK
#define STACk
#include "linked_list.h"

typedef struct stack
{
    LinkedList *data;

} Stack;

Stack *stack_new();

Element pop(Stack *stack);

void push(Element e, Stack *stack);

boolean is_empty(Stack *stack);


#endif
