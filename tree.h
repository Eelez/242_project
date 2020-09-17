//
// Created by Samuel on 10/09/2020.
//

#ifndef INC_242_PROJECT_BST_H
#define INC_242_PROJECT_BST_H

typedef struct treenode *tree;

extern void tree_free(tree t);
extern void tree_inorder(tree t, void f(char *str));
extern tree tree_insert(tree t, char *str);
extern tree tree_new();
extern void tree_preorder(tree t, void f(char *str));
extern int tree_search(tree t, char *str);

#endif //INC_242_PROJECT_BST_H
