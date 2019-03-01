/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 14:21:46
 * @LastEditTime: 2019-03-01 17:49:25
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
ArrayList *array_list_new(unsigned int cap)
{

    if (cap == 0)
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


unsigned int len(ArrayList *array)
{
    return array->length;
}

/**
 * return the capacity of array
 **/
unsigned int cap(ArrayList *array)
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
boolean is_last(unsigned int idx, ArrayList *array)
{
    return array->length == 1 + idx ? 1 : 0;
}

/**
 * return the index of the element or -1 if not exitsis;
 * O(N)
 * */
int index_of_array(Element e, ArrayList *array, compare_func cmp)
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
 * @description: 
 * @param {type} 
 * @return: 
 */
Element find(unsigned int index, ArrayList *array)
{
    if (index >= array->length)
        return NULL;
    return array->elements[index];
}

/**
 * @description: remove one element from an array by index ;
 * @param {int index}   the index 
 * @param {ArrayList *array} 
 * @param {compare_func cmp} 
 * @return: 
 */
void delete_one(unsigned int index, ArrayList *array)
{
    if (index >= array->length)
    {
        return;
    }
    return delete_many(index, 1, array);
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
    int idx = index_of_array(e, array, cmp);
    if (idx == -1)
    {
        return;
    }
    delete_one(idx, array);
}

/**
 * @description: delete a range from array
 * @param {int index} 
 * @param {int offset} always is positive number 
 * @param {ArrayList *array} 
 * @param {compare_func cmp}  compare function
 * @return: 
 */
void delete_many(unsigned int index, unsigned int offset, ArrayList *array)
{
    if (index < 0 || (offset + index) > array->length)
        return;

    /* Move back the entries following the range to be removed */
    memmove(array->elements[index], array->elements[index + offset], (array->length - (index + offset)) * sizeof(Element));
}

/**
 * insert the element in array; always in tail;
 * */
void push_back(Element e, ArrayList *array)
{
    return push_index(e, array->length, array);
}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
void push_front(Element e, ArrayList *array)
{
    return push_index(e, 0, array);
}

/**
 * insert the element in array;
 * */
void push_index(Element e, unsigned int index, ArrayList *array)
{
    if (array->length == array->capacity)
    {
        array_list_extend(array, array->length * LIST_INCREMENT_RATE);
    }
    /* Move back the entries following the range to be removed */
    memmove(array->elements[index + 1], array->elements[index], (array->length - index) * sizeof(Element));
    array->elements[index] = e;
    ++array->length;
}

void array_list_extend(ArrayList *array, unsigned int new_cap)
{
    if (new_cap <= array->capacity)
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

/**
 * @description: array reverse ; two pointer to array 
 * @param {ArrayList *array} 
 * @return: 
 */
void reverse(ArrayList *array)
{

    unsigned int left = 0, right = array->length;
    while (left <= right)
    {
        Swap(array->elements[left], array->elements[right]);
        left++;
        right--;
    }
}

/**
 * @description: simple q sort
 * @param {type} 
 * @return: 
 */
void q_sort(ArrayList *array, unsigned int left, unsigned int right, boolean desc, compare_func cmp)
{
    if (left >= right)
        return;

    // first select the mid one as the datum mark
    unsigned int mid = (left + right) / 2, startIndex = left;
    // swap
    Swap(array->elements[right], array->elements[mid]);
    for (unsigned int i = left; i < right; i++)
    {
        if ((desc == 0 && (cmp(array->elements[i], array->elements[right]) < 0)) || ((desc == 1) && (cmp(array->elements[i], array->elements[right]) > 0)))
        {
            Swap(array->elements[startIndex++], array->elements[i]);
        }
    }

    // swap the
    Swap(array->elements[right], array->elements[startIndex]);
    q_sort(array, left, startIndex - 1, desc, cmp);
    q_sort(array, startIndex + 1, right, desc, cmp);
}

// todo qsort
void sort(ArrayList *array, boolean desc, compare_func cmp)
{
    q_sort(array, 0, array->length - 1, desc, cmp);
}

