#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Graph class using an adjacency list representation
class Graph
{
private:
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int numVertices) : numVertices(numVertices)
    {
        adjacencyList.resize(numVertices);
    }

    void addEdge(int source, int destination)
    {
        adjacencyList[source].push_back(destination);
    }

    void DFS(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        stack<int> vertexStack;

        visited[startVertex] = true;
        vertexStack.push(startVertex);

        cout << "Depth-First Traversal (starting from vertex " << startVertex << "): ";

        while (!vertexStack.empty())
        {
            int currentVertex = vertexStack.top();
            vertexStack.pop();
            cout << currentVertex << " ";

            for (int neighbor : adjacencyList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    vertexStack.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    graph.DFS(0);

    return 0;
}

// Output!
// Depth-First Traversal (starting from vertex 0): 0 2 4 3 5 1
