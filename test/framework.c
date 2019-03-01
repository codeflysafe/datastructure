
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#include "framework.h"

/* Run a single test. */

static void run_test(UnitTestFunction test)
{
    /* Turn off any allocation limits that may have been set
     * by a previous test. */

    alloc_test_set_limit(-1);

    /* Run the test */

    test();

    /* Check that all memory was correctly freed back during
     * the test. */

    assert(alloc_test_get_allocated() == 0);
}

void run_tests(UnitTestFunction *tests)
{
    int i;

    for (i=0; tests[i] != NULL; ++i) {
        run_test(tests[i]);
    }
}