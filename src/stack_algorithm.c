/*
 * @Description: stack related algorithm 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-04-12 11:14:29
 * @LastEditTime: 2019-04-15 11:57:20
 */

#include "include/stack.h"

// 10 进制转 其它进制方法
// conversion
void conversion(int N, int d)
{
    Stack *stack = stack_new();
    while (N)
    {
        int temp = N % d;
        push(&temp, stack);
        N = N / d;
    }
    while (!is_empty(stack))
    {
        Element e = pop(stack);
        printf("%d", *(int *)e);
    }
}

