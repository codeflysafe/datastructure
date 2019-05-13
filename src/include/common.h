/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:40:32
 * @LastEditTime: 2019-05-13 17:24:17
 */
#ifndef DATA_STRUCTURE_COMMON_H
#define DATA_STRUCTURE_COMMON_H

// array and linked list init config
#define LIST_INIT_CAPACITY 10     // 默认初始容器是 10
#define MAX_QUEUE_SIZE 100        // 最大队列大小
#define INT_MAX 2147483647        /* max value for an int */
#define INT_MIN (-2147483647 - 1) /* min value for an int */
#define MAX_SKIP_LIST_LEVEL 64
#define SKIP_LIST_P 0.24   // p=1/4
#define IMPACT_FACTOR 0.75 // hash 碰撞比例
#define EXTEND_FACTOR 2    // hash 扩容比例
#define DEFAULT_CAPACITY 10
#define MAXIMUM_CAPACITY (1 << 30)
#define STRING_END '/0'
int max(int a, int b);
int min(int a, int b);

// define the boolean
typedef unsigned int boolean;

/**
 * A value to be sotred here;
 * */
typedef void *Element;

/**
 * @description: compare template ; and support to self-define
 * @param {type} 
 * @return: 
 */
typedef int (*compare_func)(const Element e1, const Element e2);

typedef int (*hash_code_func)(const Element e);
// compara values
int common_cmp_str(const Element key1, const Element key2);
int common_cmp_ptr(const Element key1, const Element key2);
// int hash_code(const Element key);
void swap(Element *e1, Element *e2);

#define COMMON_CMP_STR common_cmp_str;
#define COMMON_CMP_PTR common_cmp_ptr;
#define Swap swap;

#endif //DATA_STRUCTURE_COMMON_H
