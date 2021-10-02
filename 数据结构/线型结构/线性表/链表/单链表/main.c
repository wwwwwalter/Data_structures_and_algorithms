#include <stdio.h>
#include <stdlib.h>

/**
 * 单链表：有头节点
*/

typedef struct Node
{
    int data;
    struct Node *next;
} Node, Link;

Link *initLink()
{
    //创建头指针
    Link *p = NULL;

    //创建头节点
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    p = head;

    //返回头指针
    return p;
}

void freeLink(Link *p)
{
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
    Node *read = p;
    while (read->next != NULL)
    {
        read = read->next;
        printf("%d ", read->data);
    }
    printf("\n");
}

void insertNode(Link *p, int elem, int pos)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = elem;
    new->next = NULL;

    //找pos的前驱节点
    int count = 0;
    Node *pre = p;
    while (pre->next != NULL && count < pos - 1)
    {
        pre = pre->next;
        count++;
    }

    //将新节点的next指针指向前驱节点的next节点
    new->next = pre->next;
    //将前驱节点的next指针指向新节点
    pre->next = new;
}

void deleteNode(Link *p, int pos)
{
    Node *del = p;
    Node *pre = p;
    int count = 0;
    //找pos的前驱节点
    while (pre->next != NULL && count < pos - 1)
    {
        pre = pre->next;
        count++;
    }
    del = pre->next;
    pre->next = pre->next->next;
    free(del);
}

int searchNode(Link *p, int elem)
{
    int pos = 0;
    Node *s = p;

    while (s->next != NULL)
    {
        s = s->next;
        pos++;
        if (s->data == elem)
        {
            return pos;
        }
    }

    return -1;
}

void updateNode(Link *p, int pos, int newElem)
{
    //找pos的前驱节点
    int count = 0;
    Node *pre = p;
    while (pre->next != NULL && count < pos)
    {
        pre = pre->next;
        count++;
    }

    pre->data = newElem;
}

int main(void)
{

    Link *p = initLink();
    int pos = 0;

    int i = 0;
    for (i = 0; i < 10; ++i)
    {
        insertNode(p, i, i + 1);
    }

    deleteNode(p,1);

    readLink(p);
    freeLink(p);

    return 0;
}
