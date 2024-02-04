#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
} adjlist;

struct AdjList
{
    struct AdjListNode *head;
};

typedef struct Graph
{
    int V;
    struct AdjList *array;
} graph;

adjlist *newAdjListNode(int dest);
graph *createGraph(int V);
void addEdge(graph *graph, int src, int dest);
void printGraph(graph *graph);
void dfs(graph *graph, int vertex, int *arr, int n, int *top);
void printDFS(graph *graph, int *arr);
graph *exercisegraph();
int check(int *arr, int size, int element);

int main()
{
    int arr[10];

    graph *newgraph = exercisegraph();

    printGraph(newgraph);

    printDFS(newgraph, arr);

    return 0;
}

adjlist *newAdjListNode(int dest)
{
    adjlist *newNode = (adjlist *)malloc(sizeof(adjlist));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

graph *createGraph(int V)
{
    graph *new = (graph *)malloc(sizeof(graph));
    new->V = V;

    new->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    int i;
    for (i = 0; i < V; ++i)
        new->array[i].head = NULL;

    return new;
}

void addEdge(graph *graph, int src, int dest)
{
    adjlist *check = NULL;
    adjlist *newNode = newAdjListNode(dest);

    if (graph->array[src].head == NULL)
    {
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
    }
    else
    {
        check = graph->array[src].head;
        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = newNode;
    }
}

void printGraph(graph *graph)
{
    int v = 0;
    printf("Printing the Graph:\n");
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode *current = graph->array[v].head;

        printf("  Vertex %d has edges to vertices", v);
        while (current)
        {
            printf(" %d", current->dest);
            current = current->next;
        }
        printf("\n");
    }
}

void dfs(graph *graph, int vertex, int *arr, int n, int *top)
{


    struct AdjListNode *current = graph->array[vertex].head;

    if (current && check(arr, *top, current->dest))
    {
        (*top)++;
        arr[*top] = current->dest;
        n = *top;
        dfs(graph, current->dest, arr, n, top);
    }
    else
    {
        while (n >= 0)
        {
            current = graph->array[arr[n]].head;
            while (current)
            {
                if (check(arr, *top, current->dest))
                {
                    (*top)++;
                    arr[*top] = current->dest;
                    n = *top;
                    dfs(graph, current->dest, arr, n, top);
                }
                current = current->next;
            }
            n--;
        }
    }
}

void printDFS(graph *graph, int *arr)
{
    for (int vertex = 0; vertex < graph->V; vertex++)
    {
        int top = -1;
        top++;
        arr[top] = vertex;
        int n = top;
        printf("\nTraversing with DFS revusrive from vertex %d\n", vertex);
        dfs(graph, vertex, arr, n, &top);
        for (int i = 0; i <= top; i++)
            printf("  %d", arr[i]);
    }
}

graph *exercisegraph()
{
    int V = 8;
    graph *newgraph = createGraph(V);

    addEdge(newgraph, 0, 3);
    addEdge(newgraph, 0, 5);
    addEdge(newgraph, 0, 7);
    addEdge(newgraph, 1, 0);
    addEdge(newgraph, 1, 2);
    addEdge(newgraph, 1, 4);
    addEdge(newgraph, 3, 2);
    addEdge(newgraph, 4, 3);
    addEdge(newgraph, 5, 1);
    addEdge(newgraph, 5, 2);
    addEdge(newgraph, 7, 1);
    addEdge(newgraph, 7, 6);
    return newgraph;
}

int check(int *arr, int size, int element)
{
    for (int i = 0; i <= size; i++)
        if (arr[i] == element)
            return 0;
    return 1;
}
