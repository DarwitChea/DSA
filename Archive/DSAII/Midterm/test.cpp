#include <iostream>
using namespace std;

const int Table_size = 10;

class HashTable
{
private:
    int table[Table_size];

public:
    HashTable()
    {
        // Initialize the table with -1 to indicate empty slots
        for (int i = 0; i < Table_size; i++)
        {
            table[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % Table_size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        // If the index is already occupied, find the next available index
        while (table[index] != -1)
        {
            index = (index + 1) % Table_size;
        }

        // Insert the key at the empty index
        table[index] = key;
    }

    void display()
    {
        for (int i = 0; i < Table_size; i++)
        {
            cout << "Index " << i << ": ";
            if (table[i] != -1)
            {
                cout << table[i];
            }
            cout << endl;
        }
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

    // Display the resulting hash table
    hashTable.display();

    return 0;
}