#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

typedef struct node {
   int number;
   struct node *next;
}
node;

int main(void) {

    // list is a pointer to the first node
    node *list = NULL;

    // set aside some memory for a node
    node *n = malloc(sizeof(node));

    // make sure memory allocation was successful
    if(n == NULL) {
        printf("couldn't allocate memory for node\n");
        return 1;
    }

    // give our node a value
    n->number = 1;
    // and give our node a pointer to next node
    n->next = NULL;

    //now that my node exists, add it to list
    list = n;

    // add a number to the list

    // set aside some space for the node
    n = malloc(sizeof(node));
    // make sure that worked
    if(n == NULL) {
        printf("couldn't allocate memory\n");
        free(list);
        return 1;
    }
    // fill in the number & next of the node
    n->number = 2;
    n->next = NULL;
    // link node to previous one
    list->next = n;

    //third node
    n = malloc(sizeof(node));
    if(n == NULL) {
        printf("couldn't allocate memory\n");
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 4;
    n->next = NULL;
    list->next->next = n;

    for(node *current = list; current != NULL; current = current->next) {
        printf("%i\n", current->number);
    }

    // adding node to beginning of list
    // allocate memory
    n = malloc(sizeof(node));
    if(n == NULL) {
        printf("couldn't allocate memory\n");
    }
    // node's value is 0
    n->number = 0;
    // node points to beginning of list
    n->next = list;
    // beginning of list is now our new node
    list = n;
    printf("printing with 0 node added\n");
    for(node *current = list; current != NULL; current = current->next) {
        printf("%i\n", current->number);
    }

    // adding node to middle of list
    // allocate memory
    n = malloc(sizeof(node));
    if(n == NULL) {
        printf("couldn't allocate memory\n");
    }
    n->number = 3;
    n->next = list->next->next->next;
    list->next->next->next = n;
    printf("printing with 3 node added\n");
    for(node *current = list; current != NULL; current = current->next) {
        printf("%i\n", current->number);
    }

    // free up memory
    while(list != NULL) {
        node *current = list->next;
        free(list);
        list = current;
    }
}
