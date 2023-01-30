#include <stdio.h>
#include <stdlib.h>

// struct for node
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// function to create new node
struct Node *create_node(int data)
{

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    // set the data field of the new node to data
    node->data = data;

    // set the next field of the new node to null
    node->next = NULL;

    return node;
}

// function to print the linked list
void print_linkedlist(Node *current)
{

    // get a reference to head of the list
    //    struct Node *current = head;

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

// function to insert a new node at a specific index in a linked list
void insert_node(struct Node *current, int index, int x)
{
    // Create a new node to be inserted
    struct Node *new_node;

    // Check if the index is valid
    if (index < 0 || index > count_elements(current))
    {
        return;
    }
    // Allocate memory for the new node
    new_node = (struct Node *)malloc(sizeof(struct Node));
    // Assign the data to the new node
    new_node->data = x;

    // for first node
    if (index == 1)
    {
        // Update the next pointer of the new node to point to the current head
        new_node->next = head;
        // Update the head pointer to point to the new node
        head = new_node;
    }
    // for other nodes

    // move current till position - 1 times to bring it before the new node
    else
    {
        for (int i = 1; i < index - 1; i++)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}
// reverse linked list
void reverseLinkedList(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * count_elements(p));
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

int main()
{
    // struct Node *head;

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

    // Reverse Linked List
    reverseLinkedList(head);

    print_linkedlist(head);
    return 0;
}