/*
 * @Description: 
 * @LastEditors: hsjfans
 * @Email: hsjfans.scholar@gmail.com
 * @Date: 2019-02-28 19:50:08
 * @LastEditTime: 2019-02-28 20:34:31
 */
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