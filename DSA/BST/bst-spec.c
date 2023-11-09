#include <assert.h>
#include <stdio.h>
#include "bst.h"

int main()
{
    BST tree = bst_new();
    BST *bst = &tree;

    assert(bst->mass == 0);
    assert(bst_height(bst) == 0);

    bst_add(bst, 50);
    bst_add(bst, 25);
    bst_add(bst, 30);
    bst_add(bst, 28);
    bst_add(bst, 65);
    bst_add(bst, 15);

    assert(bst->mass == 6);
    assert(bst_find(bst, 30) == 1);
    assert(bst_height(bst) == 4);

    // bst_delete(bst,15);
    bst_delete_recursive(bst, 15);
    assert(bst->mass == 5);
    assert(bst_find(bst, 15) == 0);
    // bst_delete(bst,50);
    bst_traversal_inorder_recursive(bst);

    bst_delete_recursive(bst, 50);
    assert(bst->mass == 4);
    // bst_delete(bst,25);
    bst_delete_recursive(bst, 25);
    assert(bst->mass == 3);

    assert(bst_find(bst, 28) == 1);
    assert(bst_find(bst, 30) == 1);
    assert(bst_find(bst, 65) == 1);
    // bst_delete(bst,28);
    bst_delete_recursive(bst, 28);
    assert(bst->mass == 2);
    assert(bst->root->key == 65);
    assert(bst->root->left->key == 30);
    // bst_delete(bst,30);
    bst_delete_recursive(bst, 30);
    assert(bst_height(bst) == 1);
    assert(bst->mass == 1);
    assert(bst->root->key == 65);
    printf("%d\n", bst_height(bst));
    // bst_delete(bst,65);
    bst_delete_recursive(bst, 65);
    bst_add(bst, 15);
    assert(bst->mass == 1);
    printf("%d\n", bst_height(bst));
    assert(bst->root->key == 15);

    return 0;
}