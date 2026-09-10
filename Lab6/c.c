#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
  char *name;
  char *artist;
  struct Node *prev;
  struct Node *next;
};
struct Node *newNode(char *name, char *artist) {
  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->name = name;
  new->artist = artist;
  new->prev = NULL;
  new->next = NULL;
  return new;
}
struct Node *insert(struct Node *head, char *name, char *artist) {
  struct Node *n = newNode(name, artist);
  if (head == NULL) {
    return n;
  }
  struct Node *it = head;
  while (it->next) {
    it = it->next;
  }
  it->next = n;
  n->prev = it;
  return head;
}
struct Node *insertHelper(struct Node *head) {
  char *name = (char *)malloc(100 * sizeof(char));
  char *artist = (char *)malloc(100 * sizeof(char));
  printf("Enter song name: ");
  scanf(" %99[^\n]", name);
  printf("Enter artist name: ");
  scanf(" %99[^\n]", artist);
  head = insert(head, name, artist);
  return head;
}
void printPlaylist(struct Node *head, struct Node *curr) {
  struct Node *it = head;
  printf("Playlist:\n");
  while (it) {
    printf("%s by %s", it->name, it->artist);
    if (it == curr) {
      printf(" <- Currently Playing");
    }
    printf("\n \u2193 \n");
    it = it->next;
  }
  printf("END");
}
struct Node *playNext(struct Node *curr) {
  if (curr && curr->next) {
    return curr->next;
  }
  return curr;
}
struct Node *playPrev(struct Node *curr) {
  if (curr && curr->prev) {
    return curr->prev;
  }
  return curr;
}
void printPlaying(struct Node *curr) {
  if (curr) {
    printf("Now playing: %s by %s\n", curr->name, curr->artist);
  } else {
    printf("No song is currently playing.\n");
  }
}
int main() {
  int n;
  printf("Enter number of songs: ");
  scanf("%d", &n);
  struct Node *head = NULL, *curr;
  for (int i = 0; i < n; i++) {
    char *name = (char *)malloc(100 * sizeof(char));
    char *artist = (char *)malloc(100 * sizeof(char));
    printf("Enter song name: ");
    scanf(" %99[^\n]", name);
    printf("Enter artist name: ");
    scanf(" %99[^\n]", artist);
    head = insert(head, name, artist);
  }
  curr = head;
  printPlaylist(head, curr);
  playNext(curr);
  printPlaying(curr);
  playPrev(curr);
  printPlaying(curr);
  insertHelper(head);
  return 0;
}
