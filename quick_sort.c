#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = t;
    return (i + 1);
}

void quick_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quick_sort(arr, start, p - 1);
        quick_sort(arr, p + 1, end);
    }
}

int main()
{
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n %d element : ", i + 1);
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("\n\nsorted array is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    free(arr);
    return 0;
}