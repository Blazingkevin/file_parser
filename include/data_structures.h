#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#define CHAR_MAX_LENGTH 100

typedef struct
{
    char name[CHAR_MAX_LENGTH];
    int age;
    char city[CHAR_MAX_LENGTH];
} Person;

typedef struct Node
{
    Person data;
    struct Node *next;
} Node;

// define function prototypes for operations on the structure above

// create a Node
Node *create_node(Person person);

// append a node to the list
void append_node(Node **head, Person person);

// free heap memory after exit of the program
void free_list(Node *head);

#endif