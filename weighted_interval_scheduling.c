#include <stdio.h>
#include <stdlib.h>

struct job
{
    int start;
    int finish;
    int profit;
};

void swap(struct job *a, struct job *b)
{
    struct job t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(struct job jobs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (jobs[j].finish > jobs[j + 1].finish)
            {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

int latestNonConflictingJob(struct job jobs[], int n, int index)
{
    for (int i = index - 1; i >= 0; i--)
    {
        if (jobs[i].finish <= jobs[index].start)
        {
            return i;
        }
    }
    return -1;
}

int maxProfit(struct job jobs[], int n)
{
    bubbleSort(jobs, n);

    int *maxProfit = (int *)malloc((n + 1) * sizeof(int));
    maxProfit[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int prev = latestNonConflictingJob(jobs, n, i - 1);
        int currentProfit = jobs[i - 1].profit + (prev != -1 ? maxProfit[prev + 1] : 0);
        maxProfit[i] = (currentProfit > maxProfit[i - 1]) ? currentProfit : maxProfit[i - 1];
    }

    int max_profit_value = maxProfit[n];
    free(maxProfit);
    return max_profit_value;
}

int main()
{
    struct job jobs[] = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    printf("Maximum profit: %d\n", maxProfit(jobs, n));
    return 0;
}