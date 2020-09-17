//
// Created by User on 12/09/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef enum tree_e { BST, RBT } tree_t;
typedef enum node_c { RED, BLACK };

struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
    struct node *parent;
    int frequency; // how often does this value appear
    enum node_c colour; //  red or black

};


struct node* new_tree(enum tree_e type){
    tree_t = type;
    return new_node(NULL, NULL);
}



struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}


struct node* new_node(int x, struct node *parent_node)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
    p->parent = parent_node;
    p->colour = RED;

    return p;
}


void tree_fix(struct node *x ){
    if(x->parent == NULL)
        x->colour = BLACK;
        return;

    while (x.parent.colour == RED){
        if (x.parent == x.parent.parent.right){
            u = x.parent.parent.left;
            if (u.colour == RED){
                u.colour = BLACK;
                x.parent.colour = BLACK;
                x.parent.parent.colour = RED;
                x = x.parent.parent;
            }else if(x = x.parent.left) {
                x = x.parent;
                //left rotate
            }
            x.parent.colour = BLACK;
            x.parent.parent.colour = RED;
            //right rotate

        } else if (x.parent == x.parent.parent.left){
            u = x.parent.parent.right;
            if (u.colour == RED){
                u.colour = BLACK;
                x.parent.colour = BLACK;
                x.parent.parent.colour = BLACK;
                x = x.parent.parent;
            }else if(x = x.parent.right){
                x = x.parent;
                //right rotate
            }
            x.parent.colour = BLACK;
            x.parent.parent.colour = RED;
            //left rotate
        }

    }


}


struct node* insert(struct node *root, int x)
{
    //update frequency
    if (root->data == x){
        root->frequency = root->frequency+1;
        return root;
    }


    //searching for the place to insert
    if(root==NULL)
        return new_node(x, root);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    if(tree_t == RBT) {
        tree_fix(root);
    }
    return root;
}



void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}


void left_rotate(struct node *x ){
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;


}
void right_rotate(struct node *x){
    struct node *y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

int tree_depth(struct node *root){
    if(root == NULL){
        return 0;
    }
    int count = 1;

    int right = tree_depth(root->left);
    int left  = tree_depth(root->right);

    if(right>left){
        count = 1+right;
    }else if(left>right){
        count = 1+left;
    }

    return count;


}