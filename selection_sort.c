#include <stdio.h>
#include <stdlib.h>

int *selection_sort(int *arr, int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

int main()
{
    int n;
    printf("determine the size of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("\ndetermine the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("\nsorted array in ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    return 0;
}