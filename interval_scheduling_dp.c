#include <stdio.h>
#include <stdlib.h>

struct interval
{
    int start;
    int finish;
    int weight;
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

int maxTotalWeight(struct interval intervals[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (intervals[j].finish <= intervals[i].start)
            {
                dp[i] = (dp[i] > dp[j] + intervals[i].weight) ? dp[i] : dp[j] + intervals[i].weight;
            }
        }
    }

    int maxWeight = 0;
    for (int i = 0; i < n; i++)
    {
        maxWeight = (maxWeight > dp[i]) ? maxWeight : dp[i];
    }
    return maxWeight;
}

int main()
{
    struct interval intervals[] = {
        {1, 3, 5},
        {2, 4, 7},
        {3, 6, 2},
        {5, 7, 4},
        {6, 8, 6}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    // Find the maximum total weight achievable
    int maxWeight = maxTotalWeight(intervals, n);

    // Print the result
    printf("Maximum total weight achievable: %d\n", maxWeight);
    return 0;
}