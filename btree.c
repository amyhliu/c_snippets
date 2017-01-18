// Binary tree manipulation


#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *create_node(int data)
{
  struct Node *node;

  node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;

  return node;
}

void insert_node(struct Node *root, struct Node *node)
{
  if (!root) return;

  if (node->data < root->data) {
    if (root->left) {
      insert_node(root->left, node);
    }
    else {
      root->left = node;
    }
  }
  else if (node->data > root->data) {
    if (root->right) {
      insert_node(root->right, node);
    }
    else {
      root->right = node;
    }
  }
}

struct Node *create_tree(int arr[], size_t len)
{
  struct Node *root;
  struct Node *new_node;
  int i;
  
  if (!len) return NULL;

  root = create_node(arr[0]);
  for (i = 1; i < len; i++) {
    new_node = create_node(arr[i]);
    insert_node(root, new_node);
  }

  return root;
}

void delete_tree(struct Node **root)
{
  struct Node *node = *root;

  if (!node) return;

  if (node->left) delete_tree(&(node->left));
  if (node->right) delete_tree(&(node->right));
  free(node);
  *root = NULL; // can't do node = NULL here as node is local
  
}

void print_tree(struct Node *root)
{
  if (!root) return;

  /* in order */
  if (root->left) print_tree(root->left);
  printf("%d ", root->data);
  if (root->right) print_tree(root->right);
  
  /* post order */
  /*
  if (root->right) print_tree(root->right);
  printf("%d ", root->data);
  if (root->left) print_tree(root->left);
  */
}

int main(void)
{
  int arr[10] = {5, 6, 4, 9, 3, 2, 7, 8, 10, 1};
  struct Node *root = NULL;

  root = create_tree(arr, sizeof(arr)/sizeof(int));
  print_tree(root);

  delete_tree(&root);

  printf("\nEmpty tree shows nothing...\n");
  print_tree(root);
  
  return 0;
}
