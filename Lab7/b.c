#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
struct Node *newNode(int val)
{
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL)
        return NULL;
    new->val = val;
    new->next = NULL;
    return new;
}
struct Node *push(struct Node *head, int val)
{
    struct Node *Nx = newNode(val);
    if (Nx == NULL)
        return head;
    Nx->next = head;
    return Nx;
}

struct Node *pop(struct Node *head)
{
    if (!head)
        return NULL;
    struct Node *h = head->next;
    free(head);
    return h;
}
char peek(struct Node *head)
{
    if (!head)
        return 0;
    return head->val;
}
int main(){
    struct Node* st = NULL;
    int n;
    printf("Enter number of coaches: ");
    scanf("%d",&n);
    int in[n];
    int out[n];
    printf("Enter incoming positions: ");
    for(int i = 0; i<n; i++){
        scanf("%d",&in[i]);
    }
    printf("Enter outgoing positions: ");
    for(int i = 0; i<n; i++){
        scanf("%d",&out[i]);
    }
    int pout = 0;
    for(int i = 0; i<n ; i++){
        st = push(st,in[i]);
        while(st && out[pout] == peek(st)){
            st = pop(st);
            pout++;
        }
    }
    if(!st){
        printf("Valid!");
    }else{
        printf("Invalid!");
    }
    return 0;
}