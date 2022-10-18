#include <stdio.h>
#include <stdlib.h>

typedef struct node_t // should work, not tested
{
    int data;
    struct node_t *left;
    struct node_t *right;
} Node;

void deltree(Node *);

int main()
{
    Node *root = NULL; //define root
    root = (Node *)malloc(sizeof(Node)); //init
    root->data = 3; //value
    root->left = (Node *)malloc(sizeof(Node)); //init son
    root->right = (Node *)malloc(sizeof(Node)); //init son (*)

    root->left->data = 2; //value
    root->left->left = NULL; //init son
    root->left->right = NULL; //init son

    root->right = (Node *)malloc(sizeof(Node)); //? Already initialized here (*)
    root->right->data = 5;
    root->right->left = (Node *)malloc(sizeof(Node));
    root->right->right = (Node *)malloc(sizeof(Node));

    root->right->left->data = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;

    root->right->right->data = 7;
    root->right->right->left = (Node*)malloc(sizeof(Node));
    root->right->right = NULL;

    root->right->right->left->data = 6;
    root->right->right->left->left = NULL;
    root->right->right->left->right = NULL;

    deltree(root);

    return 0;
}

void deltree(Node *r)
{
    if(r != NULL)
    {
        if(r->left != NULL)
        {
            deltree(r->left); //recursive
        }
        if(r->right != NULL)
        {
            deltree(r->right); //recursive
        }
        free(r);
    }
}

