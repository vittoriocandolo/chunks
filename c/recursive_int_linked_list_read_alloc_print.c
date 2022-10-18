#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} Node;

//typedef struct node_t Node;

Node *insert(Node *p, int d);
void list(Node *p);
void delete(Node *p);

int main()
{
    Node *head = NULL;
    int n;

    while(scanf("%d", &n) == 1)
    {
        head = insert(head, n);
    }

    list(head);
    delete(head);

    return 0;
}

Node *insert(Node *p, int d)
{
    Node *q = p;
    if(p == NULL) //se non esiste un nodo
    {
        p = (Node *)malloc(sizeof(Node)); //alloco
        p->data = d; //inizializzo con il parametro dato
        p->next = NULL; //inizializzo
    }
    else
    {
        while (q->next != NULL) //se ho un nodo successivo
        {
            q = q->next; //punto a questo
        }
        q->next = (Node *)malloc(sizeof(Node)); //alloco
        q->next->data = d; //inizializzo con il parametro dato
        q->next->next = NULL; //inizializzo
    }
    return p; //ritorno sempre la testa
}

void list(Node *p)
{
    if(p == NULL)
    {
        printf("-\n");
    }
    else
    {
        printf("%d -> ",p->data);
        list(p->next); //ricorsivo
    }
}

void delete(Node *p)
{
    Node *q;

    if(p != NULL)
    {
        q = p->next;
        free(p);
        delete(q); //ricorsivo
    }
}

