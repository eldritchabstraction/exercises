#include <stdio.h>

#include "bst.h"

int main(int argc, char **argv)
{
    bst_node_t *root = generate_bst(3);

    inorder_traversal(root);

    lowest_common_ancestor(root, 0, 1);

    free_bst(root);
}
