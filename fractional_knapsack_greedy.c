#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct Item
{
    int weight;
    int value;
} Item;

// Function to compare two items by their value-to-weight ratio
int compare(const void *a, const void *b)
{
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;

    return (item2->value / item2->weight) - (item1->value / item1->weight);
}

// Function to solve the fractional knapsack problem
float fractionalKnapsack(Item *items, int n, int capacity)
{
    // Sort the items by their value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);

    // Initialize the result
    float result = 0.0;

    // Iterate over the items
    for (int i = 0; i < n; i++)
    {
        // If the current item can fit in the knapsack, add it completely
        if (items[i].weight <= capacity)
        {
            result += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            // Otherwise, add a fraction of the item to the knapsack
            result += (float)capacity / items[i].weight * items[i].value;
            break;
        }
    }

    return result;
}

// Main function
int main()
{
    // Create an array of items
    Item items[] = {{10, 10}, {2, 5}, {6, 8}, {4, 50}, {100, 1}};

    // Get the number of items
    int n = sizeof(items) / sizeof(items[0]);

    // Get the knapsack capacity
    int capacity = 25;

    // Solve the fractional knapsack problem
    float result = fractionalKnapsack(items, n, capacity);

    // Print the result
    printf("The maximum value that can be put in the knapsack is %f\n", result);

    return 0;
}