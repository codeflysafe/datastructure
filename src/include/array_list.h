/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:20:59
 * @LastEditTime: 2019-03-01 10:12:58
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
    unsigned int length;
    unsigned int capacity;
} ArrayList;

/**
 * build an empty list
 **/
ArrayList *empty_list();

/**
 *  build an array whose capacity is cap
 **/
ArrayList *array_list_new(unsigned int cap);

/**
 * return the length of array
 **/
unsigned int len(ArrayList *array);

/**
 * return the capacity of array
 **/
unsigned int cap(ArrayList *array);

/**
 * return 1  or 0 if it's empty 
 **/
boolean is_empty(ArrayList *array);

/**
 * return 1 or 0 if idx is the last index of array
 * */
boolean is_last(unsigned int idx, ArrayList *array);

/**
 * return the index of the element or -1 if not exitsis;
 * */
int index_of_array(Element e, ArrayList *array, compare_func cmp);

Element find(unsigned int index, ArrayList *array);

/**
 * delete the element in array;
 * */
void delete_one(unsigned int index, ArrayList *array);

/**
 * delete the element in array;
 * */
void delete_value(Element e, ArrayList *array, compare_func cmp);

/** 
 * @description: delete many element from an array
 * @param {type} 
 * @return: 
 */
void delete_many(unsigned int index, unsigned int offset, ArrayList *array);

/**
 * insert the element in array; always in tail;
 * */
void push_back(Element e, ArrayList *array);

/**
 * insert the element in array; always in front;
 * */
void push_front(Element e, ArrayList *array);

/**
 * insert the element in array; always in tail;
 * */
void push_index(Element e, unsigned int index, ArrayList *array);

/**
 * clear data and release the space ;
 * */
void clear(ArrayList *array);

/**
 * extend 
 * */
void array_list_extend(ArrayList *array, unsigned int cap);

/**
 * reverse the array
 * */
void reverse(ArrayList *array);

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
void q_sort(ArrayList *array, unsigned int left, unsigned int right, boolean desc, compare_func cmp);

/**
 * @description: sort the array; desc or asc
 * @param {type} 
 * @return: 
 */
void sort(ArrayList *array, boolean desc, compare_func cmp);

#endif //DATA_STRUCTURE_ARRAYLIST_H
