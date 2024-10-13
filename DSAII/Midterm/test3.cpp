#include <iostream>
#include <vector>

using namespace std;

const int T_size = 10;

class HashTable
{
private:
    int table[T_size];

public:
    HashTable()
    {
        // Initialize the table with -1 to indicate empty slots
        for (int i = 0; i < T_size; i++)
        {
            table[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % T_size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        // If the index is already occupied, find the next available index using linear probing
        while (table[index] != -1)
        {
            index = (index + 1) % T_size;
        }

        // Insert the key at the empty index
        table[index] = key;
    }

    vector<int> display()
    {
        vector<int> output;

        for (int i = 0; i < T_size; i++)
        {
            output.push_back(table[i]);
        }

        return output;
    }
};

int main()
{
    HashTable hashTable;

    // Inserting the given input into the hash table
    hashTable.insert(4371);
    hashTable.insert(1323);
    hashTable.insert(6173);
    hashTable.insert(4199);
    hashTable.insert(4344);
    hashTable.insert(9679);
    hashTable.insert(1989);

    // Get the resulting hash table as an array
    vector<int> result = hashTable.display();

    // Display the resulting hash table using array
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Index " << i << ": ";
        if (result[i] != -1)
        {
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}