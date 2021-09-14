#include <stdio.h>
#include <stdlib.h>

#define maxsize 6

/**
 * 静态链表
*/

typedef struct Node
{
    int data; //数据域
    int cur;  //游标
} Node, Link;

//创建备用链表
void reserveArr(Link *array)
{
    int i = 0;
    for (i = 0; i < maxsize; ++i)
    {
        array[i].data = -1;
        array[i].cur = i + 1;
    }
    array[maxsize - 1].cur = 0;
}

//提取分配空间
int mallocArr(Node *array)
{
    int i = array[0].cur;
    if (array[0].cur)
    {
        array[0].cur = array[i].cur;
    }
    return i;
}

//初始化静态链表
int initArr(Link *array)
{
    reserveArr(array);
    int body = mallocArr(array);
    int tempBody = body;

    int i = 0;
    for (i = 1; i < 4; ++i)
    {
        int j = mallocArr(array);
        array[tempBody].cur = j; //将申请的空闲分量链接在链表的最后一个结点后面
        array[j].data = i; //给新申请的分量的数据域初始化
        tempBody = j;      //将指向链表最后一个结点的指针后移
    }
    array[tempBody].cur = 0; //新的链表最后一个结点的指针设置为0
    return body;
}

void displayArr(Link *array, int body)
{
    int tempBody = body;
    while (array[tempBody].cur)
    {
        printf("%d %d %d\n", tempBody, array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d %d %d\n", tempBody, array[tempBody].data, array[tempBody].cur);
}

int main(void)
{
    Node array[maxsize] = {0};
    int body = initArr(array);
    displayArr(array, body);
    return 0;
}