#include <iostream>
#include <list>
using namespace std;

class Hash
{
    int BUCKET;
    list<int> *table;

public:
    Hash(int maxSize);
    void insertItem(int x);
    void insertArray(int arr[], int size);
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void displayHash();
};

Hash::Hash(int maxSize)
{
    this->BUCKET = maxSize;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::insertArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
            insertItem(arr[i]);
    }
}

void Hash::displayHash()
{
    // iterate over the size of the hash
    for (int i = 0; i < BUCKET; i++)
    {
        cout << "Index " << i << ": ";
        // check if the list at index i is empty
        if (table[i].empty())
        {
            cout << endl;
            continue;
        }

        // print the elements in the list at index i
        for (auto x : table[i])
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    Hash hash(10);
    int arr[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
    int size = sizeof(arr) / sizeof(arr[0]);

    hash.insertArray(arr, size);
    hash.displayHash();

    return 0;
}