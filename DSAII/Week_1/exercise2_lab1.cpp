#include <iostream>
using namespace std;

// Reverse Function

void recursionReverse(int n)
{
    int remainder;
    if (n < 10)
    {
        cout << n << "" << endl;
    }
    else
    {
        cout << n % 10;
        recursionReverse(n / 10);
    }
}

void nonRecurReverse(int n)
{
    while (n > 10)
    {
        cout << n % 10 << "";
        n /= 10;
    }
    cout << n << "";
}

int main()
{
    recursionReverse(379);
    nonRecurReverse(379);
}