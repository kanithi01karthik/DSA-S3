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
    if(new == NULL)
        return NULL;
    new->val = val;
    new->next = NULL;
    return new;
}
struct Node *push(struct Node *head, int val)
{
    struct Node *Nx = newNode(val);
    if(Nx == NULL)
        return head;
    Nx->next = head;
    return Nx;
}
struct Node *pop(struct Node *head)
{
    if(head == NULL)
        return NULL;
    struct Node *h = head->next;
    free(head);
    return h;
}
int peek(struct Node *head)
{
    if(head == NULL)
        return 0;
    return head->val;
}
int main()
{
    struct Node *st = NULL;
    char s[99];
    printf("Enter postfix expression: ");
    fgets(s, sizeof(s), stdin);
    int n = 0;
    int num = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            n = n * 10 + (s[i] - '0');
            num = 1;
        }
        else if(s[i] == ' ' || s[i] == '\n')
        {
            if(num)
            {
                st = push(st, n);
                n = 0;
                num = 0;
            }
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if(num)
            {
                st = push(st, n);
                n = 0;
                num = 0;
            }
            int b = peek(st);
            st = pop(st);
            int a = peek(st);
            st = pop(st);
            if(s[i] == '+')
                st = push(st, a + b);
            else if(s[i] == '-')
                st = push(st, a - b);
            else if(s[i] == '*')
                st = push(st, a * b);
            else
            {
                if(b == 0)
                {
                    printf("Division by zero");
                    return 1;
                }
                st = push(st, a / b);
            }
        }
    }
    int ans = peek(st);
    st = pop(st);
    printf("Evaluated expression: %d", ans);
    return 0;
}
