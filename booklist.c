#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

typedef struct {
    string title;
    string author;
    int year;
}
book;

typedef struct node {
    book b;
    struct node *next;
}
node;

int main(void) {

    // our list has to point somewhere
    node *list = NULL;

    //we need at least one node to start with
    node *n = malloc(sizeof(node));

    //our list points to that first node
    list = n;

    for(int i = 0; i < 4; i++) {
        // prompt user for book info
        string t = get_string("Enter book title: ");
        string a = get_string("Enter book author: ");
        int y = get_int("Enter book year: ");

        // save book info in a struct
        book current_book = {t, a, y};
        printf("book %s added\n", current_book.title);

        // set aside memory for the next node
        node *nextnode = malloc(sizeof(node));

        // make sure memory allocation was successful
        if(nextnode == NULL) {
            printf("couldn't allocate memory for next node\n");
            return 1;
        }

        n->b = current_book;
        n->next = nextnode;

        // advance to next node
        n = nextnode;
    }

    for(node *current = list; current->next != NULL; current = current->next) {
        printf("%s by %s was published in %d\n", current->b.title, current->b.author, current->b.year);
    }

}
