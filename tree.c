#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
}
node;

//prototypes
void print_tree(node *root);
bool search(node *tree, int number);
void free_tree(node *root);

int main(void) {
    node *tree = NULL;

    //create root node
    node *n = malloc(sizeof(node));
    if(n == NULL) {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    //fill in left side
    n = malloc(sizeof(node));
    if(n == NULL) {
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    //fill in right side
    n = malloc(sizeof(node));
    if(n == NULL) {
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;
    
    //print tree
    print_tree(tree);
}

void print_tree(node *root) {
    if(root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

bool search(node *tree, int number) {
    //empty tree OR last node w nowhere to go
    if(tree == NULL) {
        return false;
    }
    if(number < tree->number) {
        return search(tree->left, number);
    } else if(number > tree->number) {
        return search(tree->right, number);
    } else if(number == tree->number) {
        return true;
    }
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
