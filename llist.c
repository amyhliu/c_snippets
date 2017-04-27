// Single linked list operations

#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node *next;
};

struct Node* create_node(int data)
{
  struct Node *tmp;
  
  tmp = (struct Node*)malloc(sizeof(struct Node));
  tmp->data = data;
  tmp->next = NULL;

  return tmp;
}

void insert_node(struct Node **head, int data)
{
  struct Node *tmp;
  struct Node *prev;
  struct Node *curr;

  // insert at the beginning
  if ((*head)->data > data) {
    tmp = create_node(data);
    tmp->next = *head;
    *head = tmp;
    return;
  }

  prev = *head;
  curr = (*head)->next;
  while (curr) {
    if (curr->data > data) { // insert before curr
      tmp = create_node(data);
      prev->next = tmp;
      tmp->next = curr;
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  // insert at the end
  if (!curr) {
    tmp = create_node(data);
    prev->next = tmp;
    tmp->next = curr;
  }
}

// This function deletes all the nodes whose data is equal to the passed
// in data.
void delete_node(struct Node **head, int data)
{
  struct Node *tmp;
  struct Node *prev;
  struct Node *curr;

  if (!(*head)) return;

  // Check if head needs to be deleted
  while ((*head) && ((*head)->data == data)) {
  tmp = (*head)->next;
    free(*head);
    *head = tmp;
  }

  // Head's data is different from the passed in data
  if ((*head) && ((*head)->next)) {
    prev = *head;
    curr = (*head)->next;
    while (curr) {
      if (curr->data == data) {
	prev->next = curr->next;
	free(curr);
      }
      else {
	prev = curr;
      }
      curr = curr->next;
    }
  }
}

struct Node *create_llist(int *arr, size_t size)
{
  struct Node *head = NULL;
  struct Node *tmp = NULL;

  if (!size) return head;
  
  head = create_node(arr[0]);
  tmp = head;
  for (int i = 1; i < size; ++i) {
    tmp->next = create_node(arr[i]);
    tmp = tmp->next;
  }

  return head;
}

void reverse_llist(struct Node **head)
{
  struct Node *prev = NULL;
  struct Node *curr = *head;
  struct Node *tmp = NULL;

  while (curr) {
    tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  *head = prev;
}

// least to greatest
void sort_llist(struct Node *head)
{
  int done = 0;
  int data;
  struct Node *tmp;

  while (!done) {
    done = 1;
    for (tmp = head; tmp->next; tmp = tmp->next) {
      if (tmp->data > tmp->next->data) {
	data = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = data;
	done = 0;
      }
    }
  }
}

void delete_llist(struct Node **head)
{
  struct Node *tmp;
  
  while (*head) {
    tmp = (*head)->next;
    free(*head);
    *head = tmp;
  }

  *head = NULL;
}

void print_llist(struct Node *head)
{
  if (!head) return;
  
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }

  printf("\n");
}

int main(void)
{
  int myarr[] = {2, 2, 5, 2, 4, 7};
  struct Node *head = NULL;

  head = create_llist(myarr, sizeof(myarr)/sizeof(int));
  print_llist(head);

  delete_node(&head, 2);
  print_llist(head);

  reverse_llist(&head);
  print_llist(head);

  sort_llist(head);
  print_llist(head);

  delete_node(&head, 9);
  print_llist(head);

  insert_node(&head, 1);
  insert_node(&head, 1);
  print_llist(head);

  
  delete_llist(&head);
  print_llist(head);

  
  return 0;
}
