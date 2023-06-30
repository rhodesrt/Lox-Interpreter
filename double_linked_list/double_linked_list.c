#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;

void printList() {
  struct node *ptr = head;

  printf("[null]=>");
  while (ptr != NULL) {
    printf("%d=>", ptr->data);
    ptr = ptr->next;
  }
  printf("[null]\n");
}

void insert_first(int data) {
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->data = data;

  link->next = head;

  link->prev = NULL;

  head = link;
}

struct node * find(int data) {
  current = head;

  while (current->data != data) {
    current = current->next;
  }

  printf("%p\n", (void *) current);

  return current;
}

void delete(struct node *node) {
  struct node *previous = node->prev;
  
  previous->next = node->next;
  
  free(node);
}

int main() {
   insert_first(10);
   insert_first(20);
   insert_first(30);
   insert_first(1);
   insert_first(40);
   insert_first(56); 

   printList();

   struct node *forty = find(40);
   struct node *fifty_six = find(56);

   delete(forty);

   printList();
   return 0;
}