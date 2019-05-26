#include<iostream>
#include <stdio.h>
using namespace std;

typedef struct  node{
    int value;
    struct  node * left = NULL;
    struct  node * right = NULL;
}NODE;

void print_tree(NODE * root) {
    if (root == NULL) return;
    cout << root->value << " ";
    print_tree(root->left);
    print_tree(root->right);
}


void insert(NODE ** root, int num) {
    if (*root == NULL) {
        (*root) = new NODE();
        (*root)->value = num;
        return;
    }

    if (num <= (*root)->value) {
        insert(&(*root)->left, num);
    } else {
        insert(&(*root)->right, num);
    }
}

int main(int argc, char const *argv[]) {
    NODE * root = NULL;
    int nelems = 9;
    int elems_to_insert[nelems] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < nelems; i++) {
        insert(&root, elems_to_insert[i]);
    }

    print_tree(root);
    return 0;
}
