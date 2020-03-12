#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/include/avl_tree.h"

int avl_tree_test()
{
    int nodes[5] = {88, 70, 61, 63, 65};
    AvlTree tree = NULL;
    for (int i = 0; i < 5; i++)
    {
        tree = insert(&nodes[i], tree, common_cmp_str);
    }
    printf("oj\n");
    return 0;
}