#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int id;
  char name[100];
  int priority;
  struct Node *prev;
  struct Node *next;
};

struct Node *newNode(int id, char *name, int priority) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (!n)
    return NULL;
  n->id = id;
  strcpy(n->name, name);
  n->priority = priority;
  n->prev = NULL;
  n->next = NULL;
  return n;
}

struct Node *insert(struct Node *head, int id, char *name, int priority) {
  struct Node *n = newNode(id, name, priority);
  if (!n)
    return head;
  if (head == NULL) {
    return n;
  }
  if (priority < head->priority) {
    n->next = head;
    head->prev = n;
    return n;
  }
  struct Node *curr = head;
  while (curr->next != NULL && curr->next->priority <= priority) {
    curr = curr->next;
  }
  n->next = curr->next;
  n->prev = curr;
  if (curr->next != NULL) {
    curr->next->prev = n;
  }
  curr->next = n;
  return head;
}

struct Node *deletePatient(struct Node *head) {
  if (head == NULL) {
    printf("No patients waiting for surgery.\n");
    return NULL;
  }
  struct Node *temp = head;
  printf("Surgery completed for Patient ID: %d, Name: %s, Priority: %d\n",
         temp->id, temp->name, temp->priority);
  head = head->next;
  if (head != NULL) {
    head->prev = NULL;
  }
  free(temp);
  return head;
}

void display(struct Node *head) {
  if (head == NULL) {
    printf("No patients waiting for surgery.\n");
    return;
  }
  printf("\nPriority List of Patients Waiting for Surgery:\n");
  struct Node *curr = head;
  while (curr != NULL) {
    printf("[ID: %d, Name: %s, Priority: %d]", curr->id, curr->name,
           curr->priority);
    if (curr->next != NULL) {
      printf(" <-> ");
    }
    curr = curr->next;
  }
  printf("\n");
}

void freeList(struct Node *head) {
  while (head != NULL) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }
}

int main() {
  struct Node *head = NULL;
  int choice;
  while (1) {
    printf("\n1. Insert Patient\n");
    printf("2. Delete Patient (Surgery Completed)\n");
    printf("3. Display Patients\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
      break;
    }
    if (choice == 1) {
      int id, priority;
      char name[100];
      printf("Enter Patient ID: ");
      scanf("%d", &id);
      printf("Enter Name: ");
      scanf(" %99[^\n]", name);
      printf("Enter Priority (1 = highest, 5 = lowest): ");
      scanf("%d", &priority);
      head = insert(head, id, name, priority);
    } else if (choice == 2) {
      head = deletePatient(head);
    } else if (choice == 3) {
      display(head);
    } else if (choice == 4) {
      freeList(head);
      break;
    } else {
      printf("Invalid choice!\n");
    }
  }
  return 0;
}
