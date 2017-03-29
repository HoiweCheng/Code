#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row = 5;
    int col = 6;
    int **matrix = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++)
        *(matrix + i) = (int*)malloc(col * sizeof(int)); 
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            matrix[i][j] = 5;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
           printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}

