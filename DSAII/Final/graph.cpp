#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// Data structure to store a graph edge
struct Edge
{
    int src, dest, weight;
};

// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<Edge>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold n elements of type vector<Edge>
        adjList.resize(n);

        // add edges to the directed graph
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge);
        }
    }
};

// A BFS Node
struct Node
{
    int vertex, depth, weight;
};

// Perform BFS on graph g starting from vertex v
int findLeastCost(Graph const &g, int src, int dest, int m)
{
    // create a queue for doing BFS
    queue<Node> q;

    // enqueue source vertex
    q.push({src, 0, 0});

    // stores least-cost from source to destination
    int minCost = INT_MAX;

    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        Node node = q.front();
        q.pop();

        int v = node.vertex;
        int depth = node.depth;
        int cost = node.weight;

        // if the destination is reached and BFS depth is equal to m,
        // update the minimum cost calculated so far
        if (v == dest && depth == m)
        {
            minCost = min(minCost, cost);
        }

        // don't consider nodes having a BFS depth more than m.
        // This check will result in optimized code and handle cycles
        // in the graph (otherwise, the loop will never break)
        if (depth > m)
        {
            break;
        }

        // do for every adjacent edge of v
        for (Edge edge : g.adjList[v])
        {
            // push every vertex (discovered or undiscovered) into
            // the queue with depth as +1 of parent and cost equal
            // to the cost of parent plus the current edge weight
            q.push({edge.dest, depth + 1, cost + edge.weight});
        }
    }

    // return least-cost
    return minCost;
}

int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges =
        {
            {0, 6, -1}, {0, 1, 5}, {1, 6, 3}, {1, 5, 5}, {1, 2, 7}, {2, 3, 8}, {3, 4, 10}, {5, 2, -1}, {5, 3, 9}, {5, 4, 1}, {6, 5, 2}, {7, 6, 9}, {7, 1, 6}};

    // total number of nodes in the graph (labelled from 0 to 7)
    int n = 8;

    // build a graph from the given edges
    Graph g(edges, n);

    int src = 0, dest = 3, m = 4;

    // Perform modified BFS traversal from source vertex src
    cout << findLeastCost(g, src, dest, m);

    return 0;
}