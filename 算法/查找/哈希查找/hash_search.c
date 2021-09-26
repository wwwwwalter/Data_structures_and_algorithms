#include <stdio.h>
#include <stdlib.h>

/**
 * 哈希查找：线性探查法
*/

#define N 10

//自定义哈希函数
int hash(int value)
{
    return value % 10;
}

//创建哈希表
void createHash(int *arr, int *hashArr)
{
    int i, index;
    for (i = 0; i < 5; ++i)
    {
        index = hash(arr[i]);
        while (hashArr[index % N] != 0)
        {
            index++;
        }
        hashArr[index % N] = arr[i];
    }
}

//哈希查找算法，hashArr表示哈希表，value表示要查找的元素
int hash_search(int *hashArr, int value)
{
    //查找目标元素所在的索引
    int hashAdd = hash(value);

    ///如果探测位置为空
    if (hashArr[hashAdd] == 0)
    {
        return -1;
    }

    //如果索引位置不是目标元素，则发生碰撞
    while (hashArr[hashAdd] != value)
    {
        hashAdd = (hashAdd + 1) % N;
        //重新回到了探测开始位置，则查找失败
        if (hashAdd == hash(value))
        {
            return -1;
        }
    }

    return hashAdd;
}

int main(void)
{
    int hashAdd;
    int hashArr[N] = {0};
    int arr[5] = {5, 20, 30, 50, 55};
    createHash(arr, hashArr);

    int i = 0;
    for (i = 0; i < N; ++i)
    {
        printf("%d ", hashArr[i]);
    }
    printf("\n");

    hashAdd = hash_search(hashArr, 50);

    printf("hashAdd=%d\n", hashAdd);

    return 0;
}