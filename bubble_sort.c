#include <stdio.h>
#include <stdlib.h>
int *bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    return arr;
}

int main()
{
    int n;
    printf("determine the size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("\ndetermine the elements of the array:- \n ");
    for (int i = 0; i < n; i++)
    {
        printf("\n element %d:- ", i + 1);
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printf("\nsorted array:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    return 0;
}