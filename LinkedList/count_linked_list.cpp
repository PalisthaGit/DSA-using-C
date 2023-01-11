#include <stdio.h>
#include <stdlib.h>

// struct for node
struct Node
{
    int data;
    struct Node *next;
};

// function to create new node
struct Node *create_node(int data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // set the data field of the new node to data
    new_node->data = data;

    // set the next field of the new node to null
    new_node->next = NULL;

    return new_node;
}

// function to print the linked list
void print_linkedlist(struct Node *head)
{

    // get a reference to head of the list
    struct Node *current = head;

    // loop through the list until we reach the end
    while (current != NULL)
    {
        printf("%d", current->data);

        // let current point to the next node
        current = current->next;
        // print new line
        printf("\n");
    }
}

// function to count the number of elements in a linked list
int count_elements(struct Node *current)
{

    // initialize a variable to store the count
    int count = 0;
    // iterate through the linked list while the current pointer is not null
    while (current != 0)
    {
        // increment the count for each iteration
        count++;
        // move to the next element in the linked list
        current = current->next;
    }
    // return the final count of elements in the linked list
    return count;
}

int main()
{
    struct Node *head;

    // create first node
    struct Node *node1 = create_node(81);
    // create second node
    struct Node *node2 = create_node(99);
    // create third node
    struct Node *node3 = create_node(111);

    // link the nodes as it is linked list
    head = node1;
    node1->next = node2;
    node2->next = node3;

    // print number of elements
    int count = count_elements(head);
    printf("%d", count);

    return 0;
}