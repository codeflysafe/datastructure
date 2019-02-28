/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:20:59
 * @LastEditTime: 2019-02-28 18:57:20
 */

#ifndef DATA_STRUCTURE_ARRAYLIST_H
#define DATA_STRUCTURE_ARRAYLIST_H

/**
 * A value to be sotred here;
 * */
typedef void *Element;

/**
 *  A dynamic array that expands automatically when elements are added;
 *  The array support amortized  constant time insertion and removal of elements at the
 *  end of the array, as well as the constant time to access;
**/
typedef struct array_list_s
{
    Element *elements;
    int length;
    int capacity;
} ArrayList;

/**
 * build an empty list
 **/
ArrayList EmptyList();

/**
 * return the length of array
 **/
int len(ArrayList array);

/**
 * return the capacity of array
 **/
int cap(ArrayList array);

/**
 * return 1  or 0 if it's empty 
 **/
int IsEmpty(ArrayList array);

/**
 * return 1 or 0 if idx is the last index of array
 * */
int IsLast(int idx, ArrayList array);

/**
 * return the index of the element or -1 if not exitsis;
 * */
int find(Element e, ArrayList array);

#endif //DATA_STRUCTURE_ARRAYLIST_H
