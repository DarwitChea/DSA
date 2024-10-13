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
            adjList[edge.v].push_back(edge.w); // 1--> 0
            adjList[edge.w].push_back(edge.v); // 0 --> 1
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
        {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 3}, {2, 3}, {2, 4}, {2, 5}, {3, 5}};
    int j = 0, // start node number
        n = 5; // number of node
    Graph graph(edges, n + 1);
    printGraph(graph, j, n + 1);
}