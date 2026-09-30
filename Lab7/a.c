#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char val;
    struct Node *next;
};
struct Node *newNode(char val)
{
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL)
        return NULL;
    new->val = val;
    new->next = NULL;
    return new;
}
struct Node *push(struct Node *head, char x)
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
char peek(struct Node *head)
{
    if (!head)
        return 0;
    return head->val;
}

int main()
{
    struct Node *st = NULL;
    char s[10000];
    printf("Enter code snippet: ");
    fgets(s, sizeof(s), stdin);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '{' || s[i] == '[')
        {
            st = push(st, s[i]);
        }
        else if (s[i] == '}' || s[i] == ']')
        {
            if ((s[i] == '}' && peek(st) != '{') ||
                (s[i] == ']' && peek(st) != '['))
            {
                printf("Incorrect brackets\n");
                return 1;
            }

            st = pop(st);
        }
        else if (s[i] == '/' || s[i] == '*')
        {
            if (s[i] == '/' && s[i + 1] == '*')
            {
                st = push(st, 'c');
                i++;
            }
            else if (s[i] == '*' && s[i + 1] == '/')
            {
                if (peek(st) != 'c')
                {
                    printf("Incorrect comments\n");
                    return 1;
                }
                st = pop(st);
                i++;
            }
        }
    }

    if (st != NULL)
    {
        printf("Incorrect brackets\n");
        return 1;
    }

    printf("Correct brackets\n");

    return 0;
}