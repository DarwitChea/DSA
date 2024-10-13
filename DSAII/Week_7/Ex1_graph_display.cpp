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
            cout << vertArr[i][j] << "\t";
        }
        cout << endl;
    }
}
void add_edge(int u, int v)
{
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}
int main()
{
    add_edge(1, 2);
    add_edge(1, 5);
    add_edge(2, 3);
    add_edge(2, 4);
    add_edge(2, 5);
    add_edge(3, 4);
    add_edge(4, 5);
    displayMatrix(5);
}
