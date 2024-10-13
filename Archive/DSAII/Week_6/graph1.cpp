#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int v, w;
};
class Graph
{
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge : edges)
        {
            adjList[edge.v].push_back(edge.w);
        }
    }
};
void printGraph(Graph const &graph, int j, int n)
{
    for (int i = j; i < n; i++)
    {
        cout << i << "-";
        for (int v : graph.adjList[i])
        {
            cout << "-> " << v << " ";
        }

        cout << endl;
    }
}
int main()
{
    system("cls");
    vector<Edge> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
    int j = 0, // start node number
        n = 5; // number of node
    Graph graph(edges, n);
    printGraph(graph, j, n);
}