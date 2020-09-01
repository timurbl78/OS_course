#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void print_list(struct Node *node) {
  while(node != NULL) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}

void insert_node(struct Node *node, int value) {
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->next = node->next;
  node->next = newNode;
}

void delete_node(struct Node *head, struct Node *node) {
  while(head != NULL) {
    if (head->next == node) {
      head->next = node->next;
      break;
    }
    head = head->next;
  }
}

int main(void) {
  struct Node *head = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  struct Node *second = NULL;
  second = (struct Node*)malloc(sizeof(struct Node));
  struct Node *third = NULL;
  third = (struct Node*)malloc(sizeof(struct Node));
  head->value = 4;
  head->next = second;
  second->value = 5;
  second->next = third;
  third->value = 6;
  printf("the initial array:\n");
  print_list(head);

  printf("add 8 after 5:\n");
  insert_node(second, 8);
  printf("add 9 after 6:\n");
  insert_node(third, 9);
  print_list(head);

  printf("delete 5:\n");
  delete_node(head, second);
  print_list(head);
  printf("delete 6:\n");
  delete_node(head, third);
  print_list(head);
}
