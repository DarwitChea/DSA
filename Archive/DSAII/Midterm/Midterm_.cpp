#include <iostream>
#include <list>
#include <vector>
using namespace std;

class LinearProbing
{
public:
    int size;
    vector<int> table;
    LinearProbing(int size) : size(size), table(size, -1) {}

    int hash(int key)
    {
        return key % size;
    }

    void insertItem(int key)
    {
        int index = hash(key);

        while (table[index] != -1)
        {
            index = (index + 1) % size;
        }

        table[index] = key;
    }

    void displayHash()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            if (table[i] != -1)
            {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

class QuadraticProbing
{
public:
    int size;
    int *table;

    QuadraticProbing(int b)
    {
        this->size = b;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }

    int hashFunction(int x)
    {
        return (x % size);
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int i = 1;

        while (table[index] != -1)
        {
            index = (index + i * i) % size;
            i++;
        }

        table[index] = key;
    }

    void displayHash()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            if (table[i] != -1)
            {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

class SeparateChaining // Done as Lab
{
public:
    int bucket;
    list<int> *table;

    SeparateChaining(int b)
    {
        this->bucket = b;
        table = new list<int>[bucket];
    }

    void insertItem(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    int hashFunction(int x)
    {
        return (x % bucket);
    };

    void displayHash()
    {
        for (int i = 0; i < bucket; i++)
        {
            cout << i;
            for (auto x : table[i])
            {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

int main()
{
    system("cls");
    int arr[10] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};

    LinearProbing LinearHash(10);
    for (int i = 0; i < 7; i++)
    {
        LinearHash.insertItem(arr[i]);
    }
    cout << "Linear Probing Hash-Table: " << endl;
    LinearHash.displayHash();
    cout << endl;

    QuadraticProbing QuadraticHash(10);
    for (int i = 0; i < 7; i++)
    {
        QuadraticHash.insert(arr[i]);
    }
    cout << "Quadratic Probing Hash-Table: " << endl;
    QuadraticHash.displayHash();
    cout << endl;

    SeparateChaining SeparateHash(10);
    for (int i = 0; i < 7; i++)
    {
        SeparateHash.insertItem(arr[i]);
    }
    cout << "Separate Chaining Hash-Table: " << endl;
    SeparateHash.displayHash();
    cout << endl;
}