#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} Node;

Node *insert(Node *, int);

int main()
{
    FILE *f = fopen("test2.txt", "r");
    Node *head = NULL;
    int n;

    if(f != NULL)
    {
        while(fscanf(f, "%d", &n) == 1)
        {
            head = insert(head, n);
        }
    }

    fclose(f);

    return 0;
}

Node *insert(Node *p, int d)
{
    Node *q = p;

    if(p == NULL)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = d;
        p->next = NULL;
    }
    else
    {
        while(q->next != NULL)
        {
            q = q->next;
        }
        q->next = (Node *)malloc(sizeof(Node));
        q->next->data = d;
        q->next->next = NULL;
    }
    return p;
}

