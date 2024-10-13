#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    // Function to add an edge between two vertices
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Function to print the adjacency list
    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertex " << i << " -> ";
            for (const int &neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V = 5; // Number of vertices
    Graph graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Adjacency List:\n";
    graph.printGraph();

    return 0;
}

// Output!
// Adjacency List:
// Vertex 0 -> 1 4
// Vertex 1 -> 0 2 3 4
// Vertex 2 -> 1 3
// Vertex 3 -> 1 2 4
// Vertex 4 -> 0 1 3
