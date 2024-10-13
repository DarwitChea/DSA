#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjacencyList.resize(numVertices);
    }

    void addEdge(int from, int to)
    {
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from); // Uncomment for undirected graph
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; ++i)
        {
            cout << "Vertex " << i << " -> ";
            for (int j = 0; j < adjacencyList[i].size(); ++j)
            {
                cout << adjacencyList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.printGraph();

    return 0;
}

// Result :
// Vertex 0 -> 1 2
// Vertex 1 -> 0 3
// Vertex 2 -> 0 4
// Vertex 3 -> 1
// Vertex 4 -> 2
