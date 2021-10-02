#include <stdio.h>
#include <stdlib.h>

/**
 * 双向链表
*/

typedef struct Node
{
    struct Node *prior;
    int data;
    struct Node *next;
} Node, Link;

//初始化头节点
Link *initLine(void)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;

    Node *p = head;
    int i = 0;
    for (i = 2; i <= 5; ++i)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->prior = NULL;
        node->next = NULL;
        node->data = i;

        p->next = node;
        node->prior = p;
        p = node;
    }

    return head;
}

void freeLink(Link *head)
{
    Node *a = head;
    Node *b = head;
    for (a; a;)
    {
        a = a->next;
        free(b);
        b = a;
    }
}

Link *insertNode(Link *head, int data, int pos)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->prior = NULL;
    new->next = NULL;

    if (pos == 1)
    {
        new->next = head;
        head->prior = new;
        head = new;
    }
    else
    {
        //前驱
        Node *p = head;
        int i = 0;
        for (i = 1; i < pos - 1; ++i)
        {
            p = p->next;
        }
        //待插入位置是链表尾
        if (p->next == NULL)
        {
            p->next = new;
            new->prior = p;
        }
        else
        {
            p->next->prior = new;
            new->next = p->next;
            p->next = new;
            new->prior = p;
        }
    }
    return head;
}

Link *deleteNode(Link *head, int data)
{
    Node *del = head;
    //如果删除头节点
    if (del->data == data)
    {
        head = head->next;
        head->prior = NULL;
        free(del);
        return head;
    }
    else
    {
        for (del; del; del = del->next)
        {
            if (del->data == data)
            {
                del->prior->next = del->next;
                del->next->prior = del->prior;
                free(del);
                return head;
            }
        }
    }
}

int selectElem(Link *head, int data)
{
    int pos = 1;
    Node *s = head;
    for (s; s; s = s->next, ++pos)
    {
        if (s->data == data)
        {
            return pos;
        }
    }
    return -1;
}

Link *updateElem(Link *head, int pos, int newElem)
{
    Node *temp = head;
    int i = 0;
    for (i = 1; i < pos; ++i)
    {
        temp = temp->next;
    }
    temp->data = newElem;
    return head;
}

void readLink(Link *head)
{
    for (head; head; head = head->next)
    {
        printf("%d ", head->data);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Link *head = initLine();

    head = insertNode(head, 100, 1);
    printf("pos = %d\n", selectElem(head, 100));
    printf("pos = %d\n", selectElem(head, 2));
    printf("pos = %d\n", selectElem(head, 5));
    printf("pos = %d\n", selectElem(head, 6));
    head = deleteNode(head, 3);
    head = deleteNode(head, 100);
    printf("pos = %d\n", selectElem(head, 2));

    updateElem(head,1,1000);

    readLink(head);
    readLink(head);

    freeLink(head);

    return 0;
}