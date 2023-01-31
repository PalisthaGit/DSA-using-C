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

// merge two linked list
void merge(struct Node *p, struct Node *q)
{
    // take a pointer to point at last of the sorted linked list
    struct Node *last;

    // for the first element in the linked list
    // if the first node of first ll is smaller than first node of second
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    // if first node of second is smaller
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    // loop till p and q are not null
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}
int main()
{
    struct Node *first;
    struct Node *second;

    // create first node
    struct Node *node01 = create_node(1);
    // create second node
    struct Node *node02 = create_node(3);
    // create third node
    struct Node *node03 = create_node(5);

    // link the nodes as it is linked list
    first = node01;
    node01->next = node02;
    node02->next = node03;

    // create first node
    struct Node *node11 = create_node(2);
    // create second node
    struct Node *node12 = create_node(4);
    // create third node
    struct Node *node14 = create_node(6);

    // link the nodes as it is linked list
    second = node11;
    node11->next = node12;
    node12->next = node14;

    merge(first, second);

    print_linkedlist(third);

    return 0;
}