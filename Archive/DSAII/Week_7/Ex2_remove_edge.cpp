#include <iostream>
using namespace std;

int vertArr[10][10];
int count = 0;
void displayMatrix(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cout << vertArr[i][j] << "  ";
        }
        cout << endl;
    }
}
void add_edge(int u, int v)
{
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}
void remove_edge(int u, int v)
{
    vertArr[u][v] = 0;
    vertArr[v][u] = 0;
}
int main()
{
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 2);
    displayMatrix(4);
    remove_edge(1, 2);
    displayMatrix(4);
}
