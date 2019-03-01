//
// Created by hsjfans on 2019-03-01.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/include/array_list.h"
#include "framework.h"

int variable1, variable2, variable3, variable4;

ArrayList *generate_arraylist(void)
{
    ArrayList *arraylist;
    int i;

    arraylist = array_list_new(0);

    for (i=0; i<4; ++i) {
        push_back(&variable1,arraylist);
        push_back( &variable2,arraylist);
        push_back( &variable3,arraylist);
        push_back( &variable4,arraylist);
    }

    return arraylist;
}

void test_arraylist_append(void)
{
    ArrayList *arraylist;
    int i;

    arraylist = array_list_new(0);

    assert(arraylist->length == 0);

    /* Append some entries */

    push_back( &variable1,arraylist);
    assert(arraylist->length == 1);

    push_back( &variable2,arraylist);
    assert(arraylist->length == 2);


    push_back( &variable3,arraylist);
    assert(arraylist->length == 3);

    push_back( &variable4,arraylist);
    assert(arraylist->length == 4);


    assert(arraylist->elements[0] == &variable1);
    assert(arraylist->elements[1] == &variable2);
    assert(arraylist->elements[2] == &variable3);
    assert(arraylist->elements[3] == &variable4);

    /* Test appending many entries */

    for (i=0; i<10000; ++i) {
        push_back( NULL,arraylist);
    }

    clear(arraylist);

    /* Test low memory scenario */

}

static UnitTestFunction tests[] = {
        test_arraylist_append,
        NULL
};

int main(int argc, char *argv[])
{
    run_tests(tests);

    return 0;
}