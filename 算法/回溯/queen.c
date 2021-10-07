#include <stdio.h>
#include <stdlib.h>

/**
 * 回溯法
 * N皇后问题
*/

#define N 20 //皇后的最大数量
int q[N];    //各行皇后所在的列

//检验第k行第j列是否可以摆放皇后
int isSafe(int k, int j)
{
    int i;
    for (i = 1; i < k; ++i)
    {
        //如果有其它皇后位于同一列上，或者位于该位置的斜线上，则该位置无法使用
        if (q[i] == j || abs(i - k) == abs(q[i] - j))
        {
            return 0;
        }
    }
    return 1;
}

void print(int n)
{
    int i, j;
    static int count = 0;
    count++;
    printf("第%d个解:\n", count);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (q[i] != j)
            {
                printf("X ");
            }
            else
            {
                printf("Q ");
            }
        }
        printf("\n");
    }
}

int queen(int k, int n)
{
    if (k > n)
    {
        print(n);
    }

    int j = 0;
    for (j = 1; j <= n; ++j)
    {
        if (isSafe(k, j))
        {
            q[k] = j;
            queen(k + 1, n);
        }
    }
}

int main(void)
{

    //皇后的个数
    int n = 4;
    int count = queen(1, n);
    printf("共有%d种不同的排列方式\n", count);
    return 0;
}