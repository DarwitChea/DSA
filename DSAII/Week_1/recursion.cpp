#include <iostream>
using namespace std;

int fact = 1;

int RecursiveFact(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * RecursiveFact(num - 1);
    }
}

int NonRecursiveFact(int num)
{
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    cout << "Recursive Fact: " << RecursiveFact(4) << endl;
    cout << "Non-Recrusive Fact: " << NonRecursiveFact(4) << endl;
}
