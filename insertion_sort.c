#include <stdio.h>
#include <stdlib.h>

int *insertion_sort(int *arr, int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main()
{
    int n;
    printf("determine the size of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("\n determine the elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\n element %d:- ", i + 1);
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    printf("\n sorted array is :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    free(arr);
    return 0;
}