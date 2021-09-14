/***
 * 单循环链表：约瑟夫环
 * 人数：n
 * 报数：m
 * 从K人开始
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    struct Node *next;
} person;

person *initLink(int n)
{
    person *head = (person *)malloc(sizeof(person));
    head->id = 1;
    head->next = NULL;

    person *cur = head;
    int i = 2;
    for (i = 2; i <= n; ++i)
    {
        person *new = (person *)malloc(sizeof(person));
        new->id = i;
        new->next = NULL;

        cur->next = new;
        cur = new;
    }

    cur->next = head;
    return head;
}

void findAndKill(person *head, int k, int m)
{
    person *pre = head;


    person *cur = head;

    //第一次找编号为k的人
    while (cur->id != k)
    {
        pre = cur;
        cur = cur->next;
    }

    //开始报数
    while(cur->next!=cur){
        int i = 1;
        for(i = 1;i<m;++i){
            pre = cur;//p的前驱
            cur = cur->next;
        }
        pre->next = cur->next;//kill p
        printf("出列人的编号为：%d\n",cur->id);
        free(cur);
        cur = pre->next;
    }
    printf("胜出人：%d\n",cur->id);
    free(cur);
}

int main(int argc, char **argv)
{
    int n = 5;
    int m = 2;
    int k = 1;
    person*head = initLink(n);
    findAndKill(head,k,m);

    return 0;
}