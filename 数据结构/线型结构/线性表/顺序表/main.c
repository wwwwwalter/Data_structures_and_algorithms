#include <stdio.h>
#include <stdlib.h>

/**
 * 顺序表
*/

typedef struct Table
{
    int *head;
    int lenght; //记录当前顺序表的元素个数
    int size;   //顺序表能容纳元素的总个数
} table;

void initTable(table *t, int size)
{
    t->head = (int *)malloc(size * sizeof(int));
    t->lenght = 0;
    t->size = size;
}

void freeTable(table *t)
{
    if (t->head)
    {
        free(t->head);
        t->head = NULL;
    }
}

void readTable(table *t)
{
    int i = 0;
    for (i = 0; i < t->lenght; ++i)
    {
        printf("%d ", t->head[i]);
    }
    printf("\n");
}

void fillTable(table *t)
{
    int i = 0;
    for (i = 0; i < t->size; ++i)
    {
        t->head[i] = i;
        t->lenght++;
    }
}

void insertElem(table *t, int elem, int pos)
{
    //判断位置
    if (pos > t->lenght + 1 || pos < 1)
    {
        printf("pos error\n");
        return;
    }
    //判断容量
    if (t->lenght == t->size)
    {
        t->head = (int *)realloc(t->head, (t->size + 1) * sizeof(int));
        t->size += 1;
    }

    //先从最后一个元素开始
    int i = 0;
    for (i = t->lenght - 1; i >= pos - 1; --i)
    {
        t->head[i + 1] = t->head[i];
    }
    //最后插入
    t->head[pos - 1] = elem;
    t->lenght++;
}

int searchElem(table *t, int elem)
{
    int i = 0;
    for (i = 0; i < t->lenght; ++i)
    {
        if (t->head[i] == elem)
        {
            return i + 1;
        }
    }
    return -1;
}

void deleteElem(table *t, int pos)
{
    //判断位置
    if (pos > t->lenght || pos < 1)
    {
        printf("pos error\n");
        return;
    }
    //向前覆盖
    int i = 0;
    for (i = pos; i < t->lenght; ++i)
    {
        t->head[i - 1] = t->head[i];
    }
    t->lenght--;
}

void updateElem(table *t, int elem, int newElem)
{
    int pos = searchElem(t, elem);
    if (pos == -1)
    {
        return;
    }
    t->head[pos - 1] = newElem;
}

int main(int argc, int **argv)
{
    table lineTable = {0};
    table *t = &lineTable;
    initTable(t, 10);

    insertElem(t, 0, 1);
    insertElem(t, 1, 2);
    insertElem(t, 2, 3);

    insertElem(t, 10, 1);

    deleteElem(t, 1);
    updateElem(t, 1, 20);

    readTable(t);
    freeTable(t);
    return 0;
}