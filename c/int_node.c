#include <stdlib.h>

struct int_node
{
    int value;
    struct int_node *next;
};

struct int_node *create(int value)
{
    struct int_node *p = calloc(1, sizeof(struct int_node));
    //struct int_node *p = malloc(sizeof(struct int_node));
    p->value = value;
    p->next = NULL;
    return p;
}

int length(struct int_node *head)
{
    int len = 0;
    for(struct int_node *n = head; n; n = n->next)
    {
        len++;
    }
    return len;
}

struct int_node *find(struct int_node *head, int value)
{
    for(struct int_node *n = head; n; n = n->next)
    {
        if(n->value == value)
        {
            return n;
        }
    }
    return NULL;
}

struct int_node *last(struct int_node *head)
{
    for(struct int_node *n = head; n; n = n->next)
    {
        if(n->next == NULL)
        {
            return n;
        }
    }
    return NULL;
}

struct int_node *append(struct int_node *head1, struct int_node *head2)
{
    struct int_node *last1 = last(head1);
    last1->next = head2;
    return head1;
}

void int_node_clean(struct int_node *head)
{
    struct int_node *next = head;
    while(next)
    {
        struct int_node *n = next;
        next = n->next;
        free(n);
    }
}

