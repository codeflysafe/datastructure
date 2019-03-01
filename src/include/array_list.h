/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:20:59
 * @LastEditTime: 2019-03-01 08:45:59
 */

#ifndef DATA_STRUCTURE_ARRAYLIST_H
#define DATA_STRUCTURE_ARRAYLIST_H
#include "common.h"
/**
 *  A dynamic array that expands automatically when elements are added;
 *  The array support amortized  constant time insertion and removal of elements at the
 *  end of the array, as well as the constant time to access;
**/
typedef struct array_list
{
    Element *elements;
    int length;
    int capacity;
} ArrayList;

/**
 * build an empty list
 **/
ArrayList *empty_list();

/**
 *  build an array whose capacity is cap
 **/
ArrayList *array_list_new(int cap);

/**
 * return the length of array
 **/
int len(ArrayList *array);

/**
 * return the capacity of array
 **/
int cap(ArrayList *array);

/**
 * return 1  or 0 if it's empty 
 **/
boolean is_empty(ArrayList *array);

/**
 * return 1 or 0 if idx is the last index of array
 * */
boolean is_last(int idx, ArrayList *array);

/**
 * return the index of the element or -1 if not exitsis;
 * */
int find(Element e, ArrayList *array, int (*cmp)(Element e1, Element e2));

/**
 * delete the element in array;
 * */
void delete_one(int index, ArrayList *array, int (*cmp)(Element e1, Element e2));

/**
 * delete the element in array;
 * */
void delete_value(Element e, ArrayList *array, int (*cmp)(Element e1, Element e2));

/** 
 * @description: delete many element from an array
 * @param {type} 
 * @return: 
 */
void delete_many(int start, int end, ArrayList *array, int (*cmp)(Element e1, Element e2));

/**
 * insert the element in array; always in tail;
 * */
void insert(Element e, ArrayList *array);

/**
 * clear data and release the space ;
 * */
void clear(ArrayList *array);

/**
 * extend 
 * */
void array_list_extend(ArrayList *array, int cap);

/**
 * reserve the array
 * */
void reserve(ArrayList *array);

/**
 * @description: sort the array; desc or asc
 * @param {type} 
 * @return: 
 */
ArrayList *sort(ArrayList *array, int desc);

#endif //DATA_STRUCTURE_ARRAYLIST_H
