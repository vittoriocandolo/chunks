#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SIZE 1024

struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node *new_node(int key){
    struct node *n = malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return (n);
}

// right sub-tree starts after |NULL| == h
struct node *read(int *tree, int size, int i){
    if(size <= 0){
        return NULL;
    }
    if(tree[i] != 999999999){
        struct node *node = new_node(tree[i]);
        node->left = read(tree, size, i + 1);
        int dx;
        int c = 0;
        int k = 0;
        for(int j = i; j < size; j++){
            if(tree[j] == 999999999){
                c++;
            } else {
                k++;
            }
            if(c == k){
                dx = j + 1;
                break;
            }
        }
        node->right = read(tree, size, dx);
        return node;
    } else {
        return NULL;
    }
}

/*
Alternative is to print in-order visit and check if it is ordered (asc.)
*/

int bst_check(struct node *node, int min, int max){
    if (node == NULL)
        return 1;
    if (node->key < min || node->key > max)
        return 0;
    return bst_check(node->left, min, node->key - 1) && bst_check(node->right, node->key + 1, max);
}

void show(struct node *root){
    if(root != NULL){
        printf("%d ", root->key);
        show(root->left
);
        show(root->right);
    } else {
        printf("%s ", "NULL");
    }
}

int count_digits(int n){
    int c = 0;
    if(n == 0){
        return 1;
    } else {
        while(n != 0){
            n = n / 10;
            c++;
        }
    }
    return c;
}

int main(){
    char input[SIZE];
    fgets(input, SIZE, stdin);
    int size = strlen(input);
    int keys[SIZE];
    char *p = input;
    int i = 0;
    int j = 0;
    while(j < size){
            char c = p[0];
            if(c == 'N'){
                keys[i] = 999999999; // can't use -1 as jolly
                p = p + sizeof(char) * 5;
                i++;
                j = j + 5;
            } else if(c == '-'){
                p = p + sizeof(char);
                keys[i] = -atoi(p);
                p = p + sizeof(char) * (count_digits(keys[i]) + 1);
                i++;
                j = j + (count_digits(keys[i]) + 1);
            } else {
                keys[i] = atoi(p);
                p = p + sizeof(char) * (count_digits(keys[i]) + 1);
                i++;
                j = j + (count_digits(keys[i]) + 1);
            }
    }
    size = i;
    struct node *bt = read(keys, size, 0);
    printf("%d\n", bst_check(bt, INT_MIN, INT_MAX));
    return 0;
}