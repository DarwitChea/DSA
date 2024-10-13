#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<pair<int, int> > adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void printGraph_list(vector<pair<int, int> > adj[], int V)
{
    int v, w;
    for (int u = 1; u < V; u++)
    {
        cout << u;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\t-> \t" << v << "\t weighted: " << w << "\n";
        }
        cout << "\n";
    }
}
int main()
{
    system("cls");
    vector<pair<int, int> > adj[5];
    addEdge(adj, 1, 2, 5);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 3, 4, 2);
    printGraph_list(adj, 5);
}
