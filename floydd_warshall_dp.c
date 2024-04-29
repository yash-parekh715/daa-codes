#include <stdio.h>

#define nV 4
#define INF 99

void printMatrix(int matrix[][nV]);

void floyddWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;
    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][j] > matrix[k][j] + matrix[i][k])
                {
                    matrix[i][j] = matrix[k][j] + matrix[i][k];
                }
            }
        }
    }
    printMatrix(matrix);
    printf("\n\n");
}

void printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[nV][nV] = {
        {0, 2, 4, 6},
        {2, 0, 3, 5},
        {4, 3, 0, 1},
        {6, 5, 1, 0}};
    floyddWarshall(graph);
    return 0;
}