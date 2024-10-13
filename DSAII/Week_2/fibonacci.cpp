#include <iostream>
using namespace std;

void FibNum(n)
{
    int n;
    if (n == 0)
    {
        cout << "0";
    }
    else if (n == 1)
    {
        cout << "1";
    }
    else
    {
        cout << FibNum(n - 1) + FibNum(n - 2);
    }
}

int main()
{
    FibNum(5);
}