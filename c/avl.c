#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define SIZE 64

struct avlnode {
	int key;
	char value[SIZE];
	int h;
	struct avlnode* left;
	struct avlnode* right;
	struct avlnode* parent;
};

struct avlnode *avlfix(struct avlnode *root, struct avlnode *new);

struct avlnode *insert(struct avlnode *root, struct avlnode *new){
    
    struct avlnode *current = malloc(sizeof(*current));
    current = root;
    struct avlnode *pre = malloc(sizeof(*pre));
    pre->key = -1;
    
    while(current->key != -1){
        
        pre = current;
        
        if(new->key < current->key){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if(pre->key == -1){
        root = new;
    } else {
        
        new->parent = pre;
        
        if(new->key < pre->key){
            pre->left = new;
        } else {
            pre->right = new;
        }
    }
    return avlfix(root, new);
}

int max(int a, int b);

struct avlnode rotate_left(struct avlnode *root, struct avlnode *node){
    
    struct avlnode *p = malloc(sizeof(*node));
    p = node->parent;
    
    struct avlnode *r = malloc(sizeof(*node));
    r = node->right;
    
    node->right = r->left;
    
    if(node->right->key != -1){
        node->right->parent = node;
    }
    
    r->parent = p;
    
    if(node->parent->key == -1){
        root = r;
    } else if(node == node->parent->right){
        node->parent->right = r;
    } else {
        node->parent->left = r;
    }
    
    r->left = node;
    node->parent = r;
    
    node->h = max(node->left->h, node->right->h) + 1;
    r->h = max(r->left->h, r->right->h) + 1;
    
    return *root;
}

struct avlnode rotate_right(struct avlnode *root, struct avlnode *node){
    
    struct avlnode *p = malloc(sizeof(*node));
    p = node->parent;
    
    struct avlnode *l = malloc(sizeof(*node));
    l = node->left;
    
    node->left = l->right;
    
    if(node->left->key != -1){
        node->left->parent = node;
    }
    
    l->parent = p;
    
    if(node->parent->key == -1){
        root = l;
    } else if(node == node->parent->right){
        node->parent->right = l;
    } else {
        node->parent->left = l;
    }
    
    l->right = node;
    node->parent = l;
    
    node->h = max(node->left->h, node->right->h) + 1;
    l->h = max(l->left->h, l->right->h) + 1;
    
    return *root;
}

struct avlnode *avlfix(struct avlnode *root, struct avlnode *new){
    
    struct avlnode *pre = malloc(sizeof(*pre));
    pre = new->parent;
    
    while(pre->key != -1){ // segmentation fault (prima)
    
        pre->h = 1 + max(pre->left->h, pre->right->h);
        
        int balance = pre->left->h - pre->right->h;
        
        if(abs(balance) > 1){
            
            if(balance > 1){
                
                if(new->key > pre->left->key){
                    
                    *root = rotate_left(root, pre->left);
                    *root = rotate_right(root, pre);
                } else {
                    *root = rotate_right(root, pre);
                }
            } else if(balance < -1){
                
                if(new->key < pre->right->key){
                    
                    *root = rotate_right(root, pre->right);
                    *root = rotate_left(root, pre);
                } else {
                    *root = rotate_left(root, pre);
                }
            }
        }
        pre = pre->parent;
    }
    return root;
}

struct avlnode *find(struct avlnode *root, int key){
    
    struct avlnode *nf = malloc(sizeof(*nf));
    nf->key = -1;
    
    while(root->key != -1){
        
        if(root->key == key){
            return root;
        } else if(root->key < key){
            root = root->right;
        } else if(root->key > key){
            root = root->left;
        }
    }
    return nf;
}

struct avlnode *delete_helper(struct avlnode *root, struct avlnode *node);

struct avlnode *delete(struct avlnode *root, int key){
    
    struct avlnode *node = malloc(sizeof(*node));
    node = find(root, key);
    
    /*
        if(node->left->key == -1 && node->right->key == -1){
        delete_helper(root, node);
    } else {
    */
    node->key = INT_MAX;
    avlfix(root, node);
    delete_helper(root, node);
    //}
}

struct avlnode *delete_helper(struct avlnode *root, struct avlnode *node){
    
    if(node->parent->left == node){
            node->parent->left->key = -1;
        } else {
            node->parent->right->key = -1;
        }
}

void show(struct avlnode *root){
    
    if(root->key != -1){
        printf("%d:%s:%d ", root->key, root->value, root->h + 1);
        // Segmentation fault spostato qui
        show(root->left);
        show(root->right);
    } else {
        printf("%s ", "NULL");
    }
}

int max(int a, int b){
    if(a >= b){
        return a;
    } else {
        return b;
    }
}

/*

--- killer input ---

insert 3 three
insert 7 seven
insert 9 nine
insert 0 zero
insert 12 twelve
show
find 3
exit

*/

int main() {
    
    struct avlnode *tree = malloc(sizeof(*tree));
    tree->key = -1;
    strcpy(tree->value, "NULL");
    tree->h = 0;
    /*
    tree->left->key = -1;
    tree->right->key = -1;
    tree->parent->key = -1;
    */
    
    char input[SIZE];
    
    while(1){
        fgets(input, SIZE, stdin);
        char *p = input;
        char c = p[0];
        if(c == 'i'){
            p = p + sizeof(char)*7;
            struct avlnode *new_node = malloc(sizeof(*new_node));
            new_node->key = atoi(p);
            
            // SEGMENTATION FAULT causato da assenza parent
            struct avlnode *new_parent = malloc(sizeof(*new_parent));
            new_parent->key = -1;
            new_node->parent = new_parent;
            
            // SEGMENTATION FAULT causato (poi) da assenza figli
            struct avlnode *new_left = malloc(sizeof(*new_left));
            new_left->key = -1;
            new_node->left = new_left;
            struct avlnode *new_right = malloc(sizeof(*new_right));
            new_right->key = -1;
            new_node->right = new_right;
            
            p = p + sizeof(char)*2;
            strcpy(new_node->value, p);
            new_node->value[strlen(new_node->value)-1] = '\0';
            tree = insert(tree, new_node);
        } else if(c == 'r') { // not working
            p = p + sizeof(char)*7;
            tree = delete(tree, atoi(p));
        } else if(c == 'f'){
            p = p + sizeof(char)*5;
            printf("%s \n", find(tree, atoi(p))->value);
        } else if(c == 'c'){
            free(tree);
            struct avlnode *tree = malloc(sizeof(*tree));
            tree->key = -1;
            strcpy(tree->value, "NULL");
            tree->h = 0;
        } else if(c == 's'){
            show(tree);
        } else {
            return 0;
        }
    }
}
