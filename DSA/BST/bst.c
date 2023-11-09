#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "bst.h"

BST bst_new()
{
    BST tree = {NULL, 0};
    return tree;
}

static TreeNode *_make_treeNode_(int32_t key)
{
    TreeNode *tnode = (TreeNode *)malloc(sizeof(TreeNode));
    tnode->key = key;
    tnode->left = tnode->right = NULL;

    return tnode;
}

BST *bst_add(BST *tree, int32_t key)
{
    TreeNode *root, *parent;

    root = parent = tree->root;

    while (root != NULL && root->key != key)
    {
        parent = root;
        if (key < root->key)
        {
            root = root->left;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
    }

    if (root == NULL)
    {
        TreeNode *tnode = _make_treeNode_(key);
        if (parent == NULL)
        {
            tree->root = tnode;
        }
        else if (key < parent->key)
        {
            parent->left = tnode;
        }
        else
        {
            parent->right = tnode;
        }
        ++tree->mass;
    }
    return tree;
}

uint32_t bst_find(BST *tree, int32_t key)
{
    TreeNode *root = tree->root;

    while (root != NULL)
    {
        if (key < root->key)
        {
            root = root->left;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }

    return root != NULL;
}

uint32_t bst_mass(BST *tree)
{
    return tree->mass;
}
static uint32_t _height_(TreeNode *node)
{
    uint32_t height;
    uint32_t lheight, rheight;

    if (node == NULL)
    {
        height = 0;
    }
    else
    {
        lheight = _height_(node->left);
        rheight = _height_(node->right);

        if (lheight > rheight)
        {
            height = lheight + 1;
        }
        else
        {
            height = rheight + 1;
        }
    }

    return height;
}
uint32_t bst_height(BST *tree)
{
    return (_height_(tree->root));
}

static TreeNode *_find_min_(TreeNode *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    else
    {
        return (_find_min_(root->left));
    }
}
/* looks complex not discussed with students  */

BST *bst_delete(BST *tree, int32_t key)
{
    TreeNode *root, *parent, *temp;
    root = tree->root;
    parent = NULL;
    while (root != NULL)
    {
        if (key < root->key)
        {
            parent = root;
            root = root->left;
        }
        else if (key > root->key)
        {
            parent = root;
            root = root->right;
        }
        else if (root->left && root->right)
        {
            temp = _find_min_(root->right);
            root->key = temp->key;
            key = root->key;
            parent = root;
            root = root->right;
        }
        else
        {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            else
                root = root->left;
            if (parent != NULL)
            {
                if (key < parent->key)
                {
                    parent->left = root;
                }
                else
                {
                    parent->right = root;
                }
            }
            else
            {
                tree->root = NULL;
            }
            free(temp);
            --tree->mass;
        }
    }
    return tree;
}

static TreeNode *_bst_delete_(BST *tree, TreeNode *root, int32_t key)
{
    TreeNode *temp;
    if (root == NULL)
    {
        return root;
    }
    else if (key < root->key)
    {
        root->left = _bst_delete_(tree, root->left, key);
    }
    else if (key > root->key)
    {
        root->right = _bst_delete_(tree, root->right, key);
    }
    else if (root->left && root->right)
    {
        temp = _find_min_(root->right);
        root->key = temp->key;
        root->right = _bst_delete_(tree, root->right, root->key);
    }
    else
    {
        temp = root;
        if (root->left == NULL)
            root = root->right;
        else
            root = root->left;
        free(temp);
        --tree->mass;
    }
    return root;
}

BST *bst_delete_recursive(BST *tree, int32_t key)
{
    TreeNode *root = _bst_delete_(tree, tree->root, key);
    tree->root = root;

    return tree;
}

static void _inorder_(TreeNode *root)
{
    if (root)
    {
        _inorder_(root->left);
        printf("%d\t", root->key);
        _inorder_(root->right);
    }
}

BST *bst_traversal_inorder_recursive(BST *tree)
{
    _inorder_(tree->root);
    return tree;
}

static void _preorder_(TreeNode *root)
{
    if (root)
    {
        printf("%d\t", root->key);
        _preorder_(root->left);
        _preorder_(root->right);
    }
}

BST *bst_traversal_preorder_recursive(BST *tree)
{
    _preorder_(tree->root);
    return tree;
}

static void _postorder_(TreeNode *root)
{
    if (root)
    {
        _postorder_(root->left);
        _postorder_(root->right);
        printf("%d\t", root->key);
    }
}

BST *bst_traversal_postorder_recursive(BST *tree)
{
    _postorder_(tree->root);
    return tree;
}

/*
 *
 *
 Commented because stack ds is not visible


BST* bst_traversal_inorder_iterative(BST *root)
{
    Stack stk = stack_new(0);
    StackResult res ;
    TreeNode *root = tree->root;

    while(root != NULL || !stack_empty(&stk))
    {
        if(root) {
            stack_push(&stk,root,&res);
            root = root->left;
        } else {
            stack_pop(&stk,&res);
            root = res.data;
            printf("%d\t",root->key);
            root = root->right;
        }
    }
    stack_delete(&stk);

    return tree;

}



*/

/*
 *
 *
 Commented because queue ds is not visible


BST* bst_traversal_levelorder(BST *tree)
{
    Queue q = queue_new(0);
    QueueResult ;

    TreeNode *root = tree->root;

    queue_add(&q,root,&res);

    for(;;) {
        queue_remove(&q,&res);
        if(root)  {
            printf("%d\t",root->key);
            if(root->left) {
                queue_add(&q,root->left,&res);
            }
            if(root->right)
                queue_add(&q,root->right,&res);
            }
        } else {
            break;
        }
    }
    return tree;
}

*/