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
    int frequency;
    enum node_c colour;
};


struct tree{
    struct node root = NULL;
};


struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to find the minimum value in a node
//struct node* find_minimum(struct node *root)
//{
//    if(root == NULL)
//        return NULL;
//    else if(root->left_child != NULL) // node with minimum value will have no left child
//        return find_minimum(root->left_child); // left most element will be minimum
//    return root;
//}

//function to create a node
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

struct node* insert(struct node *root, int x)
{
    //update frequency
    if (root->data == x){
        frequency == frequency+1;
        return root;
    }


    //searching for the place to insert
    if(root==NULL)
        return new_node(x, root);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);


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



void tree_fix(struct node *root ){

}