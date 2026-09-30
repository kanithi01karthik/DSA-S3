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
struct Node *push(struct Node *head, int x)
{
    struct Node *Nx = newNode(x);
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

int peek(struct Node *head)
{
    if (!head)
        return -1;
    return head->val;
}

int main()
{
    int n;
    struct Node *st = NULL;
    printf("Enter number of buildings: ");
    scanf("%d", &n);
    int heights[n];
    printf("Enter heights: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heights[i]);
    }
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        while (st && heights[i] <= heights[peek(st)])
        {
            int p = peek(st);
            st = pop(st);
            int left = peek(st);
            int width;
            if (left == -1)
                width = i;
            else
                width = i - left - 1;
            int area = heights[p] * width;
            if (area > maxA)
                maxA = area;
        }
        st = push(st, i);
    }
    while (st)
    {
        int p = peek(st);
        st = pop(st);
        int left = peek(st);
        int width;
        if (left == -1)
            width = n;
        else
            width = n - left - 1;
        int area = heights[p] * width;
        if (area > maxA)
            maxA = area;
    }
    printf("Maximum Area: %d\n", maxA);
    return 0;
}
