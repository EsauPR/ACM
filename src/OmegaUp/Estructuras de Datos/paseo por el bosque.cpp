#include <iostream>

using namespace std;

typedef struct node {
    int value;
    struct node * left;
    struct node * right;
} NODE;


void insert(NODE * root, int num) {
    if (root == NULL) {
        root = new NODE();
        root.value = num;
        return;
    }

    if (num < root->value) {
        insert(root->left, num);
        return;
    }

    insert(root->right, num);

}


int main() {

    int nelements, num;

    cin >> nelements;

    NODE * root;

    while(nelements--) {
        cin >> num;
        insert(root, num);
    }

    return;
}
