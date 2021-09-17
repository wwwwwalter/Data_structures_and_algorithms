#include <stdio.h>
#include <stdlib.h>

/**
 * 栈：顺序栈
*/

typedef int stack;

int push(stack *p, int top, int elem)
{
    p[++top] = elem;
    return top;
}

int pop(stack *p, int top)
{
    if (top == -1)
    {
        return top;
    }
    printf("%d\n", p[top]);
    top--;
    return top;
}

int main(void)
{
    int a[100] = {0};
    int top = -1;

    top = push(a, top, 1);
    top = push(a, top, 2);

    top = pop(a, top);
    top = pop(a, top);

    return 0;
}