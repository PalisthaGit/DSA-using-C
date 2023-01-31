#include <stdio.h>
#include <stdlib.h>

// struct for node
struct Node
{
    int data;
    struct Node *next;
} *third;

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

// check if linked list is sorted
int isSorted(struct Node *p)
{

    int x = -2342;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

// Concatenates two linked lists 'first' and 'second'
void concat(struct Node *first, struct Node *second)
{
    // Assign the head of 'first' linked list to 'third'
    third = first;
    // Traverse the 'first' linked list until its end
    while (first->next != NULL)
        first = first->next;
    // Attach the head of 'second' linked list to the end of 'first' linked list
    first->next = second;
}

int main()
{
    struct Node *first;
    struct Node *second;

    // create first node
    struct Node *node01 = create_node(812343);
    // create second node
    struct Node *node02 = create_node(99);
    // create third node
    struct Node *node03 = create_node(111);

    // link the nodes as it is linked list
    first = node01;
    node01->next = node02;
    node02->next = node03;

    // create first node
    struct Node *node11 = create_node(54345);
    // create second node
    struct Node *node12 = create_node(34);
    // create third node
    struct Node *node14 = create_node(345);

    // link the nodes as it is linked list
    second = node11;
    node11->next = node12;
    node12->next = node14;

    concat(first, second);
    print_linkedlist(third);

    return 0;
}