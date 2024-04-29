// standard multiplication O(n^3)
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int a[10][10], b[10][10], mul[10][10], r, c, i, j, k;
//     // system("cls");
//     printf("enter the number of row = ");
//     scanf("%d", &r);
//     printf("enter the number of column = ");
//     scanf("%d", &c);
//     printf("enter the first matrix element = \n");
//     for (i = 0; i < r; i++)
//     {
//         for (j = 0; j < c; j++)
//         {
//             printf("A[%d][%d]: ", i + 1, j + 1);
//             scanf("%d", &a[i][j]);
//         }
//     }
//     printf("enter the second matrix element=\n");
//     for (i = 0; i < r; i++)
//     {
//         for (j = 0; j < c; j++)
//         {
//             printf("B[%d][%d]:", i + 1, j + 1);
//             scanf("%d", &b[i][j]);
//         }
//     }

//     printf("multiply of the matrix=\n");
//     for (i = 0; i < r; i++)
//     {
//         for (j = 0; j < c; j++)
//         {
//             mul[i][j] = 0;
//             for (k = 0; k < c; k++)
//             {
//                 mul[i][j] += a[i][k] * b[k][j];
//             }
//         }
//     }
//     // for printing result
//     for (i = 0; i < r; i++)
//     {
//         for (j = 0; j < c; j++)
//         {
//             printf("%d\t", mul[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// strassen's multiplication O(n^2.81)
#include <stdio.h>
#include <stdlib.h>
void add(int n, int a[][n], int b[][n], int c[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int n, int a[][n], int b[][n], int c[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + (-1) * b[i][j];
        }
    }
}

void strassen(int n, int A[][n], int B[][n], int C[][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = n / 2;

    int a11[newSize][newSize], a12[newSize][newSize], a21[newSize][newSize], a22[newSize][newSize];

    int b11[newSize][newSize], b12[newSize][newSize], b21[newSize][newSize], b22[newSize][newSize];

    int c11[newSize][newSize], c12[newSize][newSize], c21[newSize][newSize], c22[newSize][newSize];

    int p[newSize][newSize], q[newSize][newSize], r[newSize][newSize], s[newSize][newSize], t[newSize][newSize], u[newSize][newSize], v[newSize][newSize];

    int temp1[newSize][newSize], temp2[newSize][newSize];

    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // p = (a11 + a22) * (b11 + b22)
    add(newSize, a11, a22, temp1);
    add(newSize, b11, b22, temp2);
    strassen(newSize, temp1, temp2, p);
    // q = (a21 + a22)*b11
    add(newSize, a21, a22, temp1);
    strassen(newSize, temp1, b11, q);
    // r =(b12 - b22)*a11
    subtract(newSize, b12, b22, temp1);
    strassen(newSize, a11, temp1, r);
    // s = (b21 - b11)*a22
    subtract(newSize, b21, b11, temp1);
    strassen(newSize, temp1, a22, s);
    // t = (a11 + a12) * b22
    add(newSize, a11, a12, temp1);
    strassen(newSize, temp1, b22, t);
    // u = (b11 + b12)*(a21 - a22)
    add(newSize, b11, b12, temp1);
    subtract(newSize, a21, a22, temp2);
    strassen(newSize, temp1, temp2, u);
    // v = (b21 + b22)*(a11 - a12)
    add(newSize, b21, b22, temp1);
    subtract(newSize, a11, a12, temp2);
    strassen(newSize, temp1, temp2, v);

    // c11 = p + s - t + v
    add(newSize, p, s, temp1);
    subtract(newSize, temp1, t, temp2);
    add(newSize, temp2, v, c11);

    // c12 = r + t
    add(newSize, r, t, c12);

    // c21 = q + s
    add(newSize, q, s, c21);

    // c22 = p + r - q +v
    add(newSize, p, r, temp1);
    subtract(newSize, temp1, q, temp2);
    add(newSize, temp2, v, c22);

    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
}
void printMatrix(int n, int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of square matrices (nxn): ");
    scanf("%d", &n);
    int A[n][n], B[n][n], C[n][n];
    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    strassen(n, A, B, C);
    printf("Matrix C (Result of A x B):\n");
    printMatrix(n, C);
    return 0;
}