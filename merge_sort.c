#include <stdio.h>

void merge(int l, int m, int u, int arr[])
{
    int i, j, k;
    int m1 = m - l + 1;
    int m2 = u - m;

    int L[m1], R[m2];
    for (i = 0; i < m1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < m2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < m1 && j < m2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < m1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < m2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int l, int u, int arr[])
{
    if (l < u)
    {
        int m = l + (u - l) / 2;
        merge_sort(l, m, arr);
        merge_sort(m + 1, u, arr);

        merge(l, m, u, arr);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    merge_sort(0, arr_size - 1, arr);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}