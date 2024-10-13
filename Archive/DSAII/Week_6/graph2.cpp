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
        {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 7}, {6, 5}, {6, 7}};
    int j = 1, // start node number
        n = 7; // number of node
    Graph graph(edges, n + 1);
    printGraph(graph, j, n + 1);
}