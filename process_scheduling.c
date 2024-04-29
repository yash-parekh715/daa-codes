#include <stdio.h>
#include <stdlib.h>

struct task
{
    int duration;
    int deadline;
};

void swap(struct task *a, struct task *b)
{
    struct task t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(struct task tasks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tasks[j].deadline > tasks[j + 1].deadline)
            {
                swap(&tasks[j], &tasks[j + 1]);
            }
        }
    }
}

int maxLateness(struct task tasks[], int n)
{
    bubbleSort(tasks, n);
    int max_lateness = 0;
    int current_time = 0;
    int completion_time;
    for (int i = 0; i < n - 1; i++)
    {
        completion_time = current_time + tasks[i].duration;
        int lateness = (completion_time > tasks[i].deadline) ? (completion_time - tasks[i].deadline) : 0;
        if (lateness > max_lateness)
        {
            max_lateness = lateness;
        }
        current_time = completion_time;
    }
    return max_lateness;
}

int main()
{
    struct task tasks[] = {
        {3, 5},
        {4, 7},
        {2, 3},
        {5, 10}};
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    // Find the maximum lateness of scheduled tasks
    int max_lateness = maxLateness(tasks, num_tasks);

    // Print the result
    printf("Maximum lateness: %d\n", max_lateness);
    return 0;
}