#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

struct avlnode{
  int key;
  char value[SIZE];
  int h;
  struct avlnode *left;
  struct avlnode *right;
};

int height(struct avlnode *node){
  if(!node){
    return 0;
  } else {
    return node->h;
  }
}

int max(int a, int b){
  if(a >= b){
    return a;
  } else {
    return b;
  }
}

struct avlnode *new_node(int key, char *value, int h){
  struct avlnode *node = malloc(sizeof(struct avlnode));
  node->key = key;
  strcpy(node->value, value);
  node->h = 1;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct avlnode *rr(struct avlnode *node){
  struct avlnode *x = node->left;
  struct avlnode *y = x->right;
  x->right = node;
  node->left = y;
  node->h = max(height(node->left), height(node->right)) + 1;
  x->h = max(height(x->left), height(x->right)) + 1;
  return x;
}

struct avlnode *lr(struct avlnode *node){
  struct avlnode *y = node->right;
  struct avlnode *x = y->left;
  y->left = node;
  node->right = x;
  node->h = max(height(node->left), height(node->right)) + 1;
  y->h = max(height(y->left), height(y->right)) + 1;
  return y;
}

int balance(struct avlnode *node){
  if(!node){
    return 0;
  } else {
    return height(node->left) - height(node->right);
  }
}

struct avlnode *insert(struct avlnode *root, struct avlnode *node){
  if(!root){
    return node;
  }
  if(node->key < root->key){
    root->left = insert(root->left, node);
  }
  else if(node->key > root->key){
    root->right = insert(root->right, node);
  } else {
    return root;
  }
  root->h = 1 + max(height(root->left), height(root->right));
  int b = balance(root);
  if(b > 1 && node->key < root->left->key){
    return rr(root);
  }
  if(b < -1 && node->key > root->right->key){
    return lr(root);
  }
  if(b > 1 && node->key > root->left->key){
    root->left = lr(root->left);
    return rr(root);
  }
  if(b < -1 && node->key < root->right->key){
    root->right = rr(root->right);
    return lr(root);
  }
  return root;
}

struct avlnode *min(struct avlnode *node){
  struct avlnode *current = node;
  while(current->left != NULL){
    current = current->left;
  }
  return current;
}

struct avlnode *delete(struct avlnode *root, int key){
  if(!root){
    return root;
  }
  if(key < root->key){
    root->left = delete(root->left, key);
  }
  else if(key > root->key){
    root->right = delete(root->right, key);
  } else {
    if((!root->left) || (!root->right)){
      struct avlnode *temp;
      if(root->left){
        temp = root->left;
      } else {
        temp = root->right;
      }
      if(!temp){
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }
    } else {
      struct avlnode *temp = min(root->right);
      root->key = temp->key;
      strcpy(root->value, temp->value);
      root->right = delete(root->right, temp->key);
    }
  }
  if(!root){
    return root;
  }
  root->h = 1 + max(height(root->left), height(root->right));
  int b = balance(root);
  if(b > 1 && balance(root->left) >= 0){
    return rr(root);
  }
  if(b > 1 && balance(root->left) < 0){
    root->left = lr(root->left);
    return rr(root);
  }
  if(b < -1 && balance(root->right) <= 0){
    return lr(root);
  }
  if(b < -1 && balance(root->right) > 0){
    root->right = rr(root->right);
    return lr(root);
  }
  return root;
}

struct avlnode *find(struct avlnode *root, int key){
  while(root){
    if(root->key == key){
      return root;
    } else if(root->key < key){
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return NULL;
}

void show(struct avlnode *root){
  if(root){
    printf("%d:%s:%d ", root->key, root->value, root->h);
    show(root->left);
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
  struct avlnode *tree = malloc(sizeof(*tree));
  tree = NULL;
  char input[SIZE];
  while(1){
    fgets(input, SIZE, stdin);
    char *p = input;
    char c = p[0];
    if(c == 'i'){
      p = p + sizeof(char) * 7;
      struct avlnode *node = new_node(0, "0", 1);
      node->key = atoi(p);
      p = p + sizeof(char) * (count_digits(node->key) + 1);
      strcpy(node->value, p);
      node->value[strlen(node->value) - 1] = '\0';
      tree = insert(tree, node);
    } else if(c == 'r'){
      p = p + sizeof(char) * 7;
      if(!tree->left && !tree->right){
        tree = NULL;
      } else {
        tree = delete(tree, atoi(p));
      }
    } else if(c == 'f'){
      p = p + sizeof(char) * 5;
      printf("%s \n", find(tree, atoi(p))->value);
    } else if(c == 'c'){
      tree = NULL;
    } else if(c == 's'){
      show(tree);
      printf("\n");
    } else {
      return 0;
    }
  }
}
