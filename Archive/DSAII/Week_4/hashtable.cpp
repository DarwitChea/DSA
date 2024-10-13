
#include <iostream>
#include <list>

using namespace std;

class Hash
{
    // No. of buckets
    int BUCKET;
    // Pointer to an array containing buckets.
    list<int> *table;

public:
    // Constructor
    Hash(int v);

    // Inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // Hash function to map values to key
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}
void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // get the hash index
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}
void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int arr[] = {20, 11, 12, 23, 5, 17, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Hash h(10);

    for (int i = 0; i < n; i++)
        h.insertItem(arr[i]);

    h.displayHash();
}
