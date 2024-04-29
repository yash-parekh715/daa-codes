#include <stdio.h>
#include <stdlib.h>

struct License
{
    int id;
    float growth_rate;
};

void swap(struct License *a, struct License *b)
{
    struct License temp = *a;
    *a = *b;
    *b = temp;
}

int partitition(struct License licenses[], int low, int high)
{
    float pivot = licenses[high].growth_rate;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (licenses[i].growth_rate > pivot)
        {
            i++;
            swap(&licenses[i], &licenses[j]);
        }
    }
    swap(&licenses[i + 1], &licenses[high]);
    return (i + 1);
}

void quickSort(struct License licenses[], int low, int high)
{
    if (low < high)
    {
        float pi = partitition(licenses, low, high);
        quickSort(licenses, low, pi - 1);
        quickSort(licenses, pi + 1, high);
    }
}

void buyLicenses(struct License licenses[], int n)
{
    quickSort(licenses, 0, n - 1);
    printf("the order for buying licenses is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", licenses[i].id);
    }
}

int main()
{
    int n;
    printf("enter the numeber of licenses:- ");
    scanf("%d", &n);
    struct License licenses[n];
    for (int i = 0; i < n; i++)
    {
        licenses[i].id = i + 1;
        printf("\nEnter license %d details:\n", i + 1);
        scanf("%f", &licenses[i].growth_rate);
    }
    buyLicenses(licenses, n);
    return 0;
}