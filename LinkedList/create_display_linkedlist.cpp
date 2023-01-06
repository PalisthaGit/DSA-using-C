#include <stdio.h>
#include <stdlib.h>

//struct for node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head, *current;
    // create an array to create a linkedlist from ot
    int A[] = {3, 5, 7, 10, 15};
    for(int i = 0; i<sizeof(A);i++) {
        struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
        // add data to new node
        new_node->data = A[i];
        new_node->next = NULL;

        // if there is no head node
        // add head node
        if(head== NULL){
            head = new_node;
            current = new_node;
        }

        else {
            current->next = new_node;
            current = new_node;
        }

    }
    return 0;
}