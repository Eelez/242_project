//
// Created by Samuel on 10/09/2020.
//

#include "tree.h"


typedef enum tree_e { BST, RBT } tree_t;




struct node {

    int data;
    struct node *right;
    struct node  *left;

};

struct node* search(struct node *root, int x ){
    if(root==NULL || root->data == x)
        return root;
    else if(x>root->data)
        return search(root->right, x);
    else
        return search(root->left, x)
}

struct node* create_tree(int x , ){
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node* insert(struct node *root, int x){
    if(root == NULL)
        return create_tree(x);
    else if(x > root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);

    return root;
}


void inorder(struct node *root)
{
    if(root!=NULL){
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}