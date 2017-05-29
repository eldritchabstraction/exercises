#ifndef BST_H
#define BST_H

typedef struct bst_node_t
{
    int d;
    struct bst_node_t *l;
    struct bst_node_t *r;
} bst_node_t;

/*
 * generate_bst: generates a bst given some level; return root of bst
 *
 * ideas:
 * - we know how many nodes there are given level, it's (2 ^ level) - 1
 * - take an array and divide it up into a bst?
 */
bst_node_t * generate_bst(int levels);

/*
 * free_bst: free the memory associated with bst
 */
void free_bst(bst_node_t *root);

/*
 * lowest common ancestor: given two values, find the lowest common ancestor
 * - technically, this would use binary search, but maybe we don't want to mess
 *   around with virtual functions this time around?
 * - returns the value of the lowest common ancestor
 */

int lowest_common_ancestor(bst_node_t *root, int a, int b);

/*
 * TODO: make this
 * inorder successor: given some number find the node corresponding to the next
 * "inorder" node
 */

bst_node_t * inorder_successor(bst_node_t *root, int target);

/*
 * inorder_traversal: given some root, inorder traverse and print out bst
 */
void inorder_traversal(bst_node_t *root, int retval = 0,
    int (*traversal_operation)(bst_node_t *) = NULL);

/*
 * post_order_traversal: given some root, post order traverse and do something
 */
int post_order_traversal(bst_node_t *root, int retval = 0,
    int (*traversal_operation)(bst_node_t *) = NULL);
#endif // BST_H
