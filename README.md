# Traversing a Graph with DFS in C

### Data Structures:
- `AdjListNode`: A structure for an adjacency list node containing an integer `dest` representing the destination vertex, and a pointer to the next node.
- `AdjList`: A structure that contains a pointer to the first `AdjListNode` of the list.
- `Graph`: A structure that represents a graph; it has an integer `V` indicating the number of vertices, and an array of `AdjList`.

### Functions:
- `newAdjListNode(int dest)`: Creates a new adjacency list node.
- `createGraph(int V)`: Initializes a graph with `V` vertices.
- `addEdge(graph *graph, int src, int dest)`: Adds an edge from vertex `src` to vertex `dest`.
- `printGraph(graph *graph)`: Prints the graph's adjacency lists for each vertex.
- `dfs(graph *graph, int vertex, int *arr, int n, int *top)`: Recursively performs a DFS traversal starting from the given vertex, tracking the visited vertices in an array `arr`.
- `printDFS(graph *graph, int *arr)`: Calls `dfs` for each vertex in the graph and prints out the DFS traversal order.
- `exercisegraph()`: Creates a specific graph based on the edges added in the function, corresponding to the graph structure shown in the image you've provided.
- `check(int *arr, int size, int element)`: Checks if an element is already in the array (used to avoid revisiting nodes in DFS).

### Main Execution (`main`):
- It initializes an array `arr` to keep track of the DFS traversal order.
- Creates a graph using `exercisegraph()` function which sets up the graph as shown in your image.
- Prints the graph's adjacency lists.
- Performs a DFS traversal from each vertex and prints the order of traversal.

### How DFS is Implemented:
The `dfs` function is designed to traverse the graph in a depth-first manner. It uses an array `arr` to store the order of traversal and an integer `top` as an index to keep track of the last element in `arr`. The `check` function is used to avoid revisiting nodes that are already in `arr`. The DFS continues recursively, exploring as far as possible along each branch before backtracking.

### The Graph in the Image:
The image shows a directed graph with 8 vertices (0 to 7). The arrows represent the directed edges between the vertices. The code constructs this graph in the `exercisegraph` function and should traverse it according to the DFS algorithm when `printDFS` is called.

![image](https://github.com/mehdinejjar86/graphs-dfs-bfs/assets/67825314/75a9b284-42ad-42b8-b505-f75e6fe6da59)

