#include <stdio.h>
#include <stdlib.h>

typedef struct __NODE__
{
    int data; // value of the node
    struct __NODE__ *next; // pointer to the next node
    struct __NODE__ *prev; // pointer to the previous node
} Node;


typedef struct __LIST__
{
    Node *head; // pointer to the first node
    Node *mid; // pointer to the middle node
    Node *tail; // pointer to the last node

    int size; // number of nodes in the list
} List;

List *new_list()
{
    List *newList = (List *)malloc(sizeof(List));
    newList->head = NULL;
    newList->mid = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

void add_to_list(List *list, Node *newNode)
{
    if (list->head == NULL)
    {
        list->head = newNode;
        list->mid = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }

    list->size++;
}


Node *new_node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void add_node(Node *head, Node *newNode)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void insert_node(Node *head, Node *newNode, int index)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == index)
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            newNode->next->prev = newNode;
            break;
        }
        temp = temp->next;
        i++;
    }
}

void insert_first(Node **head, Node *newNode)
{
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void delete_node(Node *head, int index)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == index)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            break;
        }
        temp = temp->next;
        i++;
    }
}

void delete_first(Node **head)
{
    Node *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

void delete_last(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}


int main()
{
    Node *head = new_node(0);
    add_node(head, new_node(1));
    add_node(head, new_node(2));
    add_node(head, new_node(3));
    insert_first(&head, new_node(4));

    print_list(head);
    delete_node(head, 2);
    print_list(head);
    

    return 0;
}
