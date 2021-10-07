#include <stdio.h>
#include <stdlib.h>

/**
 * 栈：链栈
*/

typedef struct Node
{
    int data;
    struct Node *next;
} Node, Link;

Link *push(Link *stack, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = stack;
    stack = new;
    return stack;
}

Link *pop(Link *stack)
{
    if (stack)
    {
        Node *p = stack;
        printf("top:%d\n", p->data);
        stack = stack->next;
        free(p);
        return stack;
    }
    else
    {
        printf("stack empty\n");
        return stack;
    }
}


int main(void){

    Link *stack = NULL;
    stack = push(stack,1);
    stack = push(stack,2);

    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);

    return 0;
}