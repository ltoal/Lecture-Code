#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

#define SIZE 20

struct node {
    string data;
    int key;
    //pointer - if using linked lists
    struct node *next;
};

struct node* hashArray[SIZE];
struct node* item;

//prototypes
//search
node *search(int key);
//insert
void insert(int key, string data);
//delete
//print

int hashCode(int key) {
    return key % SIZE;
}

node *search(int key) {
    int hashIndex = hashCode(key);
    
    //if we have no linked lists
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex].key == key) {
            return hashArray[hashIndex];
        }
        //in case we had moved further looking for empty space
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
    
    //if we have linked lists
    int hashIndex = hashCode(key);
    node current = hashArray[hashIndex];
    while(current->next != NULL) {
        if(current->key == key) {
            return current;
        }
        current=current->next;
    }
    return NULL;
}

void insert(int key, string data) {
  node *newnode = malloc(sizeof(node));
  newnode->data = data;
  newnode->key = key;
  
  int hashIndex = hashCode(key);
  
  //find next empty space approach
  while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
    ++hashIndex;
    hashIndex %= SIZE;
  }
  hashArray[hashIndex] = node;
  
  //add to list approach
  if(hashArray[hashIndex] == NULL) {
      hashArray[hashIndex] = node;
  } else {
    //if something already there
    //link node to that pre-existing list
    node->next = hashArray[hashIndex];
    hashArray[hashIndex] = node;
  }
}

int main() {
    item = malloc(sizeof(node));
    item->data = "";
    item->key = -1;
}
