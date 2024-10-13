#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists; // Adjacency Lists to represent the graph.
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);
    void printGraph(Graph const &graph, int n);
};
void Graph::addEdge(int v, int w)
{
    adjLists[v].push_back(w);
    adjLists[w].push_back(v);
}
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
};
void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);
    list<int>::iterator i;
    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " --> ";
        queue.pop_front();
        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}
void Graph::printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto it = graph.adjLists[i].begin(); it != graph.adjLists[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
}
int main()
{
    system("cls");
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.printGraph(graph, 5);
    graph.BFS(0);
}
