#include <stdio.h>

/**
 * 回溯法
 * 迷宫问题
*/

typedef enum
{
    false,
    true
} bool;

#define ROW 5
#define COL 5

bool find = false;

bool canMove(char maze[ROW][COL], int row, int col)
{
    //在地图内，不是黑色，没走过
    return row >= 0 && row <= ROW - 1 && col >= 0 && col <= COL - 1 && maze[row][col] != '0' && maze[row][col] != 'Y';
}

void printmaze(char maze[ROW][COL])
{
    int i, j;
    for (i = 0; i < ROW; ++i)
    {
        for (j = 0; j < COL; ++j)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void maze_puzzle(char maze[ROW][COL], int row, int col, int outrow, int outcol)
{
    maze[row][col] = 'Y';
    if (row == outrow && col == outcol)
    {
        find = true;
        printf("成功走出迷宫，路线图为:\n");
        printmaze(maze);
        return;
    }

    if (canMove(maze, row - 1, col))
    {
        maze_puzzle(maze, row - 1, col, outrow, outcol);
        maze[row - 1][col] = '1';
    }

    if (canMove(maze, row, col - 1))
    {
        maze_puzzle(maze, row, col - 1, outrow, outcol);
        maze[row][col - 1] = '1';
    }

    if (canMove(maze, row + 1, col))
    {
        maze_puzzle(maze, row + 1, col, outrow, outcol);
        maze[row + 1][col] = '1';
    }

    if (canMove(maze, row, col + 1))
    {
        maze_puzzle(maze, row, col + 1, outrow, outcol);
        maze[row][col + 1] = '1';
    }
}

int main(void)
{
    char maze[ROW][COL] = {
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'1', '0', '0', '1', '0'},
        {'1', '0', '0', '1', '1'}};
    maze_puzzle(maze, 0, 0, ROW - 1, COL - 1);
    if (find == false)
    {
        printf("未找到可行路线\n");
    }
    return 0;
}
