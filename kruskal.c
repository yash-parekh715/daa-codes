// #include <stdio.h>
// #include <stdlib.h>

// struct edge
// {
//     int src, dest, weight;
// };

// struct subset
// {
//     int parent;
// };

// struct kruskal
// {
//     int E, V;
//     struct edge *edge;
// };

// struct kruskal *createGraph(int V, int E)
// {
//     struct kruskal *graph = (struct kruskal *)malloc(sizeof(struct kruskal));
//     graph->V = V;
//     graph->E = E;
//     graph->edge = (struct edge *)malloc(E * sizeof(struct edge));
//     return graph;
// }

// int find(struct subset subsets[], int i)
// {
//     if (subsets[i].parent != i)
//     {
//         subsets[i].parent = find(subsets, subsets[i].parent);
//     }
//     return subsets[i].parent;
// }

// int Union(struct subset subsets[], int x, int y)
// {
//     int xroot = find(subsets, x);
//     int yroot = find(subsets, y);
//     subsets[xroot].parent = yroot;
// }

// void kruskalMST(struct kruskal *graph)
// {
//     int V = graph->V;
//     int E = graph->E;
//     struct edge result[V];
//     int e = 0;
//     for (int i = 0; i < E - 1; i++)
//     {
//         for (int j = 0; j < E - i; j++)
//         {
//             if (graph->edge[j].weight > graph->edge[j + 1].weight)
//             {
//                 struct edge temp = graph->edge[j];
//                 graph->edge[j] = graph->edge[j + 1];
//                 graph->edge[j + 1] = temp;
//             }
//         }
//     }
//     struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));
//     for (int v = 0; v < V; v++)
//     {
//         subsets[v].parent = v;
//     }
//     int i = 0;
//     while (e < V - 1 && i < E)
//     {
//         struct edge next_edge = graph->edge[i++];
//         int x = find(subsets, next_edge.src);
//         int y = find(subsets, next_edge.dest);
//         if (x != y)
//         {
//             result[e++] = next_edge;
//             Union(subsets, x, y);
//         }
//     }
//     printf("Edges in the MST:\n");

//     for (i = 0; i < e; ++i)

//         printf("%d -- %d, weight: %d\n", result[i].src, result[i].dest, result[i].weight);

//     free(subsets);
// }

// int main()
// {
//     int V = 4; // Number of vertices

// int E = 5; // Number of edges

// struct Kruskal *graph = createGraph(V, E);

// // Add edge 0-1

// graph->edge[0].src = 0;

// graph->edge[0].dest = 1;

// graph->edge[0].weight = 10;

// // Add edge 0-2

// graph->edge[1].src = 0;

// graph->edge[1].dest = 2;

// graph->edge[1].weight = 6;

// // Add edge 0-3

// graph->edge[2].src = 0;

// graph->edge[2].dest = 3;

// graph->edge[2].weight = 5;

// // Add edge 1-3

// graph->edge[3].src = 1;

// graph->edge[3].dest = 3;

// graph->edge[3].weight = 15;

// // Add edge 2-3

// graph->edge[4].src = 2;

// graph->edge[4].dest = 3;

// graph->edge[4].weight = 4;

// KruskalMST(graph);

//     return 0;
// }
#include <stdio.h>

#include <stdlib.h>

// Struct to represent an edge in the graph

struct Edge

{

    int src, dest, weight;
};

// Struct to represent a subset for union-find

struct Subset

{

    int parent;
};

// Kruskal's algorithm

struct Kruskal

{

    int V, E; // Number of vertices and edges in the graph

    struct Edge *edge; // Array to store all edges (array of structures)
};

// Create a new graph with V vertices and E edges

struct Kruskal *createGraph(int V, int E)

{

    struct Kruskal *graph = (struct Kruskal *)malloc(sizeof(struct Kruskal)); //(allocating memory of type kruskal)

    graph->V = V;

    graph->E = E;

    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));

    return graph;
}

// to find parent node

int find(struct Subset subsets[], int i)

{

    if (subsets[i].parent != i)

    {

        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

// Union of two sets and declaring y as parent of x

void Union(struct Subset subsets[], int x, int y)

{

    int xroot = find(subsets, x);

    int yroot = find(subsets, y);

    subsets[xroot].parent = yroot;
}

// Apply Kruskal's algorithm to find MST of the graph

void KruskalMST(struct Kruskal *graph)

{

    int V = graph->V;

    int E = graph->E;

    struct Edge result[V]; // To store the resulting MST

    int e = 0; // counter for result

    // Sort all edges in non-decreasing order of weight using simple bubble sort

    for (int i = 0; i < E - 1; i++)

    {

        for (int j = 0; j < E - i - 1; j++)

        {

            if (graph->edge[j].weight > graph->edge[j + 1].weight)

            {

                struct Edge temp = graph->edge[j];

                graph->edge[j] = graph->edge[j + 1];

                graph->edge[j + 1] = temp;
            }
        }
    }

    // creating subset to store details of parent

    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize subsets by setting them as thier parent

    for (int v = 0; v < V; ++v)

    {

        subsets[v].parent = v;
    }

    int i = 0; // counter for next edge

    while (e < V - 1 && i < E)

    {

        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);

        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it in result and increment the index

        if (x != y)

        {

            result[e++] = next_edge;

            Union(subsets, x, y);
        }
    }

    // Print the resulting MST

    printf("Edges in the MST:\n");

    for (i = 0; i < e; ++i)

        printf("%d -- %d, weight: %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

int main()

{

    int V = 4; // Number of vertices

    int E = 5; // Number of edges

    struct Kruskal *graph = createGraph(V, E);

    // Add edge 0-1

    graph->edge[0].src = 0;

    graph->edge[0].dest = 1;

    graph->edge[0].weight = 10;

    // Add edge 0-2

    graph->edge[1].src = 0;

    graph->edge[1].dest = 2;

    graph->edge[1].weight = 6;

    // Add edge 0-3

    graph->edge[2].src = 0;

    graph->edge[2].dest = 3;

    graph->edge[2].weight = 5;

    // Add edge 1-3

    graph->edge[3].src = 1;

    graph->edge[3].dest = 3;

    graph->edge[3].weight = 15;

    // Add edge 2-3

    graph->edge[4].src = 2;

    graph->edge[4].dest = 3;

    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}