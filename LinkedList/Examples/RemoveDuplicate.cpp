#include <stdio.h>
#include <stdlib.h>

// struct for linked list node
struct Node
{
    int data;
    struct Node *next;
};

// function to create a new node with the given data
struct Node *create_node(int data)
{
    // allocate memory for the new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // set the data field of the new node to the given data
    new_node->data = data;

    // set the next field of the new node to null
    new_node->next = NULL;

    return new_node;
}

// function to print the linked list
void print_linkedlist(struct Node *head)
{
    // get a reference to the head of the list
    struct Node *current = head;

    // loop through the list until we reach the end
    while (current != NULL)
    {
        printf("%d\n", current->data);

        // let current point to the next node
        current = current->next;
    }
}

// function to remove duplicates from the linked list
void removeDuplicate(struct Node *current)
{
    // get a reference to the next node
    struct Node *next_node = current->next;

    // loop through the linked list until we reach the end
    while (next_node != NULL)
    {
        // check if the current node's data is different from the next node's data
        if (current->data != next_node->data)
        {
            // move the current node to the next node
            current = next_node;
            // get a reference to the node after the next node
            next_node = next_node->next;
        }
        else
        {
            // skip the next node by linking the current node to the node after the next node
            current->next = next_node->next;
            // free the memory occupied by the next node
            free(next_node);
            // get a reference to the node after the next node
            next_node = current->next;
        }
    }
}

int main()
{
    // create a head reference to the linked list
    struct Node *head;

    // create the first node with data 3
    struct Node *node1 = create_node(3);
    // create the second node with data 4
    struct Node *node2 = create_node(4);
    // create the third node with data 4
    struct Node *node3 = create_node(4);
    // create the fourth node with data 8
    struct Node *node4 = create_node(8);
    // create the fifth node with data 8
    struct Node *node5 = create_node(8);
    // create the sixth node with data 8
    struct Node *node6 = create_node(8);

    // link the nodes as a linked list
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    // remove duplicates from the linked list
    removeDuplicate(head);

    // call print_linkedlist to print the linked list after removing duplicates
    print_linkedlist(head);

    return 0;
}
