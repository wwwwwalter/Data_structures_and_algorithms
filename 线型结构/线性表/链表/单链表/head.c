/**
 * 单链表：没有头节点
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node, Link;

Link *initLink()
{
    //创建头指针
    Node *p = NULL;

    // //创建第一个节点
    // Node *first = (Node *)malloc(sizeof(Node));
    // first->data = 0;
    // first->next = NULL;

    // p = first;
    return p;
}

void freeLink(Link *p)
{
    if (p == NULL)
    {
        return;
    }

    Node *a = p;
    Node *b = p;

    while (a != NULL)
    {
        a = a->next;
        free(b);
        b = a;
    }
}

void readLink(Link *p)
{
    if (p == NULL)
    {
        return;
    }
    Node *read = p;
    while (read != NULL)
    {
        printf("%d ", read->data);
        read = read->next;
    }
    printf("\n");
}

void insertNode(Link **p, int elem, int pos)
{
    //构建新节点
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = elem;
    new->next = NULL;

    if (*p == NULL)
    {
        *p = new;
    }
    else
    {
        if (pos == 1)
        {
            new->next = *p;
            *p = new;
        }
        else
        {
            //找pos的前驱节点
            int count = 0;
            Node *pre = *p;
            while (pre->next != NULL && count < pos - 2)
            {
                pre = pre->next;
                count++;
            }
            new->next = pre->next;
            pre->next = new;
        }
    }
}

void deleteNode(Link *p, int pos)
{
    if (p == NULL)
    {
        return;
    }

    if(pos==1){
        Node *del = p;
        p = p->next;
        free(del);
        return;
    }

    //找pos的前驱节点
    int count = 0;
    Node *pre = p;
    while (pre->next != NULL && count < pos - 2)
    {
        pre = pre->next;
        count++;
    }
    Node *del = pre->next;
    pre->next = pre->next->next;
    free(del);
}

int searchNode(Link *p, int elem)
{
    return 0;
}

void updateNode(Link *p, int pos, int newElem)
{
}

// //迭代反转链表
// Link *iteration_reverse(Link *p)
// {
// }

// //递归反转链表
// Link *recursive_reverse(Link *p)
// {
// }
// //头插法反转链表
// Link *head_reverse(Link *p)
// {
// }

// //就地逆置法反转链表
// Link *local_reverse(Link *p)
// {
// }

int main(void)
{
    Node *p = initLink();
    int i = 0;
    for (i = 1; i <= 5; ++i)
    {
        insertNode(&p, i, i + 1);
    }

    readLink(p);
    freeLink(p);

    return 0;
}