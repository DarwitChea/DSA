#include <iostream>
using namespace std;

// Power Function

int a, n;

int recursionPow(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return a * recursionPow(a, n - 1);
    }
}

int nonRecurPow(int a, int n)
{
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= a;
    }
    return sum;
}

int main()
{
    cout << recursionPow(2, 3) << endl;
    cout << nonRecurPow(2, 3) << endl;
}