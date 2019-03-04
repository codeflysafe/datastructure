/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 19:50:08
 * @LastEditTime: 2019-03-04 10:24:29
 */
#include <string.h>
#include "include/common.h"

/**
 * @description: comparable 
 * @param {type} 
 * @return: 1 or 0
 */
int common_cmp_str(const Element key1, const Element key2)
{
    return strcmp(key1, key2);
}
/**
 * @description: compara the address of key1 and key2 pointer
 * @param {type} 
 * @return: -1 if key1 less than key2;
 *          0 if key1 == key2 ; 
 *          1 if key1 > key2; 
 *          
 */
int common_cmp_ptr(const Element key1, const Element key2)
{
    if (key1 < key2)
    {
        return -1;
    }
    else if (key1 > key2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @description: swap two element 
 * @param {type} 
 * @return: 
 */
void swap(Element *e1, Element *e2)
{

    Element e = e1;
    e1 = e2;
    e2 = e;
}
