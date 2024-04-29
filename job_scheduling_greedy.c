// Implement interval scheduling algorithm. Given n𝒏 events with their starting and ending times, find a schedule that includes as many events as possible. It is not possible to select an event partially. For example, consider the following example:
// Event 	Starting time 	Ending time
// A 	            1 	          3
// B 	            2 	          5
// C 	            3 	          9
// D 	            6 	          8

// Here, maximum number of events that can be scheduled is 2. We can schedule B and D together.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Event
{
    char name[40];
    int stime;
    int ftime;
};
void print(struct Event event[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("process: %s | start time: %d | end time: %d", event[i].name, event[i].stime, event[i].ftime);
        printf("\n");
    }
}

void sort(struct Event event[], int n)
{
    struct Event t;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; i < n; i++)
        {
            if (event[i].ftime > event[j].ftime)
            {
                t = event[i];
                event[i] = event[j];
                event[j] = t;
            }
        }
    }
    print(event, n);
}

void selection(struct Event event[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (event[i].ftime >= event[i + 1].stime)
        {
            printf("process: %s | start time: %d | finishing time: %d\n", event[i].name, event[i].stime, event[i].ftime);
            i++;
        }
        else
        {
            printf("process: %s | start time: %d | finishing time: %d\n", event[i].name, event[i].stime, event[i].ftime);
        }
    }
}

void main()
{
    int num;
    printf("enter the number of events: ");
    scanf("%d", &num);
    struct Event event[num];
    printf("enter the event details:- \n");
    for (int i = 0; i < num; i++)
    {
        printf("\nprocess name: ");
        scanf("%s", &event[i].name);
        printf("\n start time: ");
        scanf("%d", &event[i].stime);
        printf("\nend time: ");
        scanf("%d", &event[i].ftime);
    }

    printf("\nlist of all events\n");
    print(event, num);
    printf("\nlist of all events sorted by their finishing time\n");
    sort(event, num);
    printf("\n selected events are: \n");
    selection(event, num);
}