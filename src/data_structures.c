#include <stdio.h>
#include <stdlib.h>

#include "data_structures.h"

Node *create_node(Person person)
{
    Node *new_node = (Node *)malloc(sizeof(Person));

    if (new_node == NULL)
    {
        perror("Error allocating memory for new node");
        exit(EXIT_FAILURE);
    }

    new_node->data = person;
    new_node->next = NULL;

    return new_node;
}

void append_node(Node **head, Person person)
{
    // create a new node
    Node *new_node = create_node(person);

    // if this is the first node, set this as the list head
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        // find last node and attach the new node to the last
        Node *curr = *head;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = new_node;
    }
}

void free_list(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        // preserve next node
        Node *next = curr->next;
        // free memomry allocated to the current node
        free(curr);
        curr = next;
    }
}
