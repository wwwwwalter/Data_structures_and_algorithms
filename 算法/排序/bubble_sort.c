#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * 冒泡排序
*/

void bubble_sort(int table[], int size)
{
    int i, j;
    int bigger;
    for (i = 0; i < size - 1; ++i)
    {
        for (j = 0; j < size - 1 - i; ++j)
        {
            if (table[j] > table[j + 1])
            {
                bigger = table[j];
                table[j] = table[j + 1];
                table[j + 1] = bigger;
            }
        }
    }
}

void read_table(int *table, int size)
{
    int i = 0;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int main(void)
{
    int table[5] = {14, 33, 27, 35, 10};
    bubble_sort(table, 5);
    read_table(table, 5);

    return 0;
}