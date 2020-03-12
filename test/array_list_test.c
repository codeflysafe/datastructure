//
// Created by hsjfans on 2019-03-01.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/include/array_list.h"

int test(int argc, char *argv[])
{
    ArrayList *array = array_list_new(0);

    assert(array->length == 0);

    assert(array->capacity == LIST_INIT_CAPACITY);

    return 0;
}
