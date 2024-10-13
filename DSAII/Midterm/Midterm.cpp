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
    void insertArray(int arr[]);

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
    while (table[index].size() == 1)
    {
        index = (index + 1) % BUCKET;
    }
    table[index].push_back(key);
}
// void insert(int key) {
//         int hash = key % capacity; // Calculate initial hash value

//         while (table[hash] != -1) {
//             hash = (hash + 1) % capacity; // Linearly probe to the next slot
//         }

//         table[hash] = key; // Insert the key into the found empty slot
//     }
void Hash::insertArray(int *arr)
{
    for (int i = 0; i <= BUCKET - 1; i++)
    {
        if (arr[i] != 0)
            insertItem(arr[i]);
    }
}

void Hash::displayHash()
{
    // iterate size of hash
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        // x is the current container of table at i index
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    system("cls");
    Hash hash = Hash(10);
    int arr[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
    hash.insertArray(arr);
    hash.displayHash();
}

// int arr[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};