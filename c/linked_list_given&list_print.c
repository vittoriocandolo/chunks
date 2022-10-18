#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} Node;

void print_list(Node *);

int main()
{
    Node *head = NULL;
    head =(Node *)malloc(sizeof(Node));
    head->data = 11;

    head->next = (Node *)malloc(sizeof(Node));
    head->next->data = 6;

    head->next->next = (Node *)malloc(sizeof(Node));
    head->next->next->data = 30;

    head->next->next->next = NULL;

    print_list(head);

    return 0;
}

void print_list(Node *head)
{
    if(head != NULL)
    {
        printf("%d\n", head->data);

        print_list(head->next);
    }
}

