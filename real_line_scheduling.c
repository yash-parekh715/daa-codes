#include <stdio.h>
#include <stdlib.h>

struct interval
{
    int start;
    int finish;
};

void swap(struct interval *a, struct interval *b)
{
    struct interval t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(struct interval intervals[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (intervals[j].finish > intervals[j + 1].finish)
            {
                swap(&intervals[j], &intervals[j + 1]);
            }
        }
    }
}

int maxNonOverlappingIntervals(struct interval intervals[], int n)
{
    int count = 1;
    bubbleSort(intervals, n);
    int end_time = intervals[0].finish;
    for (int i = 0; i < n; i++)
    {
        if (intervals[i].start >= end_time)
        {
            count++;
            end_time = intervals[i].finish;
        }
    }
    return count;
}

int main()
{
    struct interval intervals[] = {
        {1, 3},
        {2, 4},
        {3, 6},
        {5, 7},
        {6, 8}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    // Find the maximum number of non-overlapping intervals
    int maxIntervals = maxNonOverlappingIntervals(intervals, n);

    // Print the result
    printf("Maximum non-overlapping intervals: %d\n", maxIntervals);
    return 0;
}