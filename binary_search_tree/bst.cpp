#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(fmt, args...) printf("DEBUG: " fmt, ##args)
#define DEBUG_PRINT_CLEAN(fmt, args...) printf(fmt, ##args)
#else
#define DEBUG_PRINT(x) do {} while(0)
#define DEBUG_PRINT_CLEAN do{} while(0)
#endif

/*
 * convert_array_to_bst: take an array of ints and dynamically generate a bst
 * - recursive algorithm
 * - i'm promising not to augment the array only to read from it
 * - the *node should actually be assigned the malloc'd object else NULL
 */
static void convert_array_to_bst(int left, int right,
    bst_node_t **node, const int *array)
{
    // kill condition
    if (left == right)
    {
        (*node) = new bst_node_t();
        (*node)->d = left;
        (*node)->l = NULL;
        (*node)->r = NULL;
        return;
    }

    int mid = (left + right) / 2;

    // allocate the middle object?
    DEBUG_PRINT("left: %d, right %d, mid: %d\n", left, right, mid);
    (*node) = new bst_node_t();
    (*node)->d = mid;

    // continue on left side
    convert_array_to_bst(left, mid - 1, &((*node)->l), array);

    // continue on right side
    convert_array_to_bst(mid + 1, right, &((*node)->r), array);
}

bst_node_t * generate_bst(int level)
{
    bst_node_t *root = NULL;
    int nodes = 1;

    // The number of nodes given some level is (2 ^ level) - 1
    for (int i = 0; i < level; i++)
    {
        nodes = nodes * 2;
    }
    nodes--;
    DEBUG_PRINT("number of nodes %d given level %d\n", nodes, level);

    int * array = new int[nodes];

    DEBUG_PRINT("array: ");
    for (int i = 0; i < nodes; ++i)
    {
        DEBUG_PRINT_CLEAN("%d ", i);
        array[i] = i;
    }
    DEBUG_PRINT_CLEAN("\n");

    // Now we generate the bst converting the array to a bst

    convert_array_to_bst(0, nodes - 1, &root, array);

    if (root == NULL)
    {
        // we've got a problem
        exit(1);
    }

    delete array;

    return root;
}

/*
 * CRAZINESS, instead of being passed by value (which would be expected), a
 * c-array is passed by reference by default
 */
static void b_search_into_array(bst_node_t *node, int array[], int target, int index)
{
    array[index] = node->d;


    if (node->d == target)
        return;
    else if (node->d < target)
        b_search_into_array(node->r, array, target, index + 1);
    else if (node->d > target)
        b_search_into_array(node->l, array, target, index + 1);
}

int lowest_common_ancestor(bst_node_t *root, int a, int b)
{
    // run the algorithm for the first number a
    int array_a[10], array_b[10];

    memset(array_a, -1, sizeof(int) * 10);
    memset(array_b, -1, sizeof(int) * 10);
    b_search_into_array(root, array_a, a, 0);

    DEBUG_PRINT("search for %d array: ", a);
    for (int i = 0; i < 10; ++i)
        DEBUG_PRINT_CLEAN("%d ", array_a[i]);
    DEBUG_PRINT_CLEAN("\n");

    // run the algorithm for the second number b
    b_search_into_array(root, array_b, b, 0);

    DEBUG_PRINT("search for %d array: ", b);
    for (int i = 0; i < 10; ++i)
        DEBUG_PRINT_CLEAN("%d ", array_b[i]);
    DEBUG_PRINT_CLEAN("\n");

    for (int i = 0; i < 10; ++i)
    {
        if (array_a[i] == array_b[i])
            continue;
        else
            printf("lowest common ancestor: %d\n", array_a[i - 1]);
    }

    return 0;
}


static int delete_bst_node(bst_node_t *node)
{
    DEBUG_PRINT("deleting node%d\n", node->d);
    delete node;
    return 0;
}

void inorder_traversal(bst_node_t *root, int retval,
    int (*traversal_operation)(bst_node_t *))
{
    // look left
    if (root->l)
        inorder_traversal(root->l, retval, (*traversal_operation));

    // do something
    printf("@node%d\n", root->d);

    // look right
    if (root->r)
        inorder_traversal(root->r, retval, (*traversal_operation));
}

int post_order_traversal(bst_node_t *root, int retval,
    int (*traversal_operation)(bst_node_t *))
{
    // look left
    if (root->l)
        post_order_traversal(root->l, retval, (*traversal_operation));

    // look right
    if (root->r)
        post_order_traversal(root->r, retval, (*traversal_operation));

    // do something
    (*traversal_operation)(root);

    return retval;
}

void free_bst(bst_node_t * root)
{
    post_order_traversal(root, 0, delete_bst_node);
}
