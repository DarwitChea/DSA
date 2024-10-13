#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

// Function to add edge
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Function to print graph
void printGraph_list(vector<pair<int, int>> adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << u;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\t->\t" << v << "\tweighted: " << w << "\n";
        }
        cout << "\n";
    }
}

// Function to find max cost path
void findMaxCostPath(vector<pair<int, int>> adj[], int source, vector<bool> &visited, stack<int> &currentPath, stack<int> &maxPath, int &maxCost, int currentCost)
{
    visited[source] = true;
    currentPath.push(source);
    if (currentCost > maxCost)
    {
        maxCost = currentCost;
        maxPath = currentPath;
    }
    for (auto it = adj[source].begin(); it != adj[source].end(); it++)
    {
        int neighbor = it->first;
        int weight = it->second;

        if (!visited[neighbor])
        {
            findMaxCostPath(adj, neighbor, visited, currentPath, maxPath, maxCost, currentCost + weight);
        }
    }
    visited[source] = false;
    currentPath.pop();
}
void findMaximumCostPath(vector<pair<int, int>> adj[], int source)
{
    int V = adj->size();
    vector<bool> visited(V, false);
    stack<int> currentPath, maxPath;
    int maxCost = numeric_limits<int>::min();
    findMaxCostPath(adj, source, visited, currentPath, maxPath, maxCost, 0);
    cout << "The maximum cost route from source vertex " << source << " is: " << endl;
    while (!maxPath.empty())
    {
        cout << maxPath.top();
        maxPath.pop();
        if (!maxPath.empty())
        {
            cout << " -> ";
        }
    }
    cout << "\nTotal cost = " << maxCost << endl;
}

// Main Function
int main()
{
    system("cls");
    vector<pair<int, int>> adj[9];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 2, 4);
    addEdge(adj, 5, 3, 14);
    addEdge(adj, 6, 5, 2);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 7, 8, 7);
    int sourceVertex = 0;
    printGraph_list(adj, 9);
    findMaximumCostPath(adj, sourceVertex);
    cout << endl;
    return 0;
}