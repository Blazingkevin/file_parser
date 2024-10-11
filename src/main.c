#include <stdio.h>
#include <string.h>
#include "data_structures.h"

int main()
{

    // just a simple test for the core data structure
    Person person1;
    strncpy(person1.name, "Kevin", CHAR_MAX_LENGTH);
    person1.age = 20;
    strncpy(person1.city, "Ajegunle", CHAR_MAX_LENGTH);

    Person person2;
    strncpy(person2.name, "Uti", CHAR_MAX_LENGTH);
    person2.age = 24;
    strncpy(person2.city, "Neww City", CHAR_MAX_LENGTH);

    // create head node
    Node *head = NULL;

    // append persons to list
    append_node(&head, person1);
    append_node(&head, person2);

    // try to print items from list

    Node *curr = head;
    while (curr != NULL)
    {
        printf("Name: %s, Age: %d, City: %s\n", curr->data.name, curr->data.age, curr->data.city);
        curr = curr->next;
    }

    return 0;
}