/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:21:46
 * @LastEditTime: 2019-03-01 08:46:56
 */
#include <stdio.h>
#include <stdlib.h>
#include "include/array_list.h"

/**
 * build an empty list
 **/
ArrayList *empty_list()
{
    return array_list_new(LIST_INIT_CAPACITY);
}

/**
 *  build an array whose capacity is cap
 **/
ArrayList *array_list_new(int cap)
{

    if (cap <= 0)
    {
        cap = LIST_INIT_CAPACITY;
    }
    ArrayList *temp;
    // allocate the data array
    temp = (ArrayList *)malloc(sizeof(ArrayList));
    if (temp == NULL)
    {
        return NULL;
    }

    temp->capacity = cap;
    temp->length = 0;

    // allocate the data array
    temp->elements = malloc(cap * sizeof(Element));
    if (temp->elements == NULL)
    {
        // release the space
        free(temp);
        return NULL;
    }
    return temp;
}

/**
 * return the length of array
 **/
int len(ArrayList *array)
{
    return array->length;
}

/**
 * return the capacity of array
 **/
int cap(ArrayList *array)
{
    return array->capacity;
}

/**
 * return 1  or 0 if it's empty 
 **/
boolean is_empty(ArrayList *array)
{
    return array->length == 0 ? 1 : 0;
}

/**
 * return 1 or 0 if idx is the last index of array
 * */
boolean is_last(int idx, ArrayList *array)
{
    return array->length == 1 + idx ? 1 : 0;
}

/**
 * return the index of the element or -1 if not exitsis;
 * O(N)
 * */
int find(Element e, ArrayList *array, compare_func cmp)
{
    for (int i = 0; i < array->length; ++i)
    {
        if (cmp(e, array->elements[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}
/**
 * @description: remove one element from an array by index ;
 * @param {int index}   the index 
 * @param {ArrayList *array} 
 * @param {compare_func cmp} 
 * @return: 
 */
void delete_one(int index, ArrayList *array, compare_func cmp)
{
    if (index >= array->length)
    {
        return;
    }
    gitz
}

/**
 * @description: remove value from an array list if exists ;
 * @param {Element e}  the value expect to  be removed;
 * @param {ArrayList *array} 
 * @param {compare_func cmp}  compare function
 * @return: 
 */
void delete_value(Element e, ArrayList *array, compare_func cmp)
{
    int idx = find(e, array, cmp);
    if (idx == -1)
    {
        return;
    }
    delete_one(idx, array, cmp);
}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
void delete_many(int start, int end, ArrayList *array, int (*cmp)(Element e1, Element e2))
{
}

/**
 * insert the element in array; always in tail;
 * */
void insert(Element e, ArrayList *array)
{
    if (array->length == array->capacity)
    {
        array_list_extend(array, array->capacity * 2);
    }
    array->elements[array->length - 1] = e;
    ++array->length;
}

void array_list_extend(ArrayList *array, int new_cap)
{
    if (new_cap <= cap)
    {
        return;
    }
    Element *data;
    data = realloc(array->elements, new_cap * sizeof(Element));
    if (data == NULL)
    {
        return;
    }
    else
    {
        array->elements = data;
        array->capacity = new_cap;
    }
}
/**
 * clear data and release the space ;
 * */
void clear(ArrayList *array)
{
    if (array != NULL)
    {
        free(array->elements);
        free(array);
    }
}

ArrayList *sort(ArrayList *array, int desc)
{
    return array;
}
