#include <iostream>
#include <cmath>
#include <list>
using namespace std;
class Hash
{
    int BUCKET;
    // Create a sequence container from list library type int and set list's name to table
    list<string> *table;

    const int PRIME_CONST = 31;

public:
    Hash(int maxSize);
    void insertItem(string x);
    void insertArray(string arr[]);
    void deleteItem(string key);
    long hashFunction(string key)
    {
        long hashCode = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hashCode += key[i] * pow(PRIME_CONST, i);
        }
        return hashCode % 10;
    }
    void displayHash();
    void searchItem(string key);
};
Hash::Hash(int maxSize)
{
    // This constructor initialize max size of the table
    // By set table to the size of BUCKET
    this->BUCKET = maxSize;
    table = new list<string>[BUCKET];
}
void Hash::insertItem(string key)
{
    // Hash the key
    int index = hashFunction(key);
    // Push the key to correspondng index to the end of the list
    table[index].push_back(key);
}
void Hash::insertArray(string *letters)
{
    // travel throw the list size
    for (int i = 0; i <= BUCKET - 1; i++)
    {
        insertItem(letters[i]);
    }
}
void Hash::deleteItem(string key)
{
    int index = hashFunction(key);
    // Iterate each container in list
    list<string>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }
    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index]
            .erase(i);
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
void Hash::searchItem(string key)
{
    int index = hashFunction(key);
    // Iterate each container in list
    list<string>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        // if found break thus i stop where the break is
        if (*i == key)
            break;
    }
    if (i != table[index].end())
        cout << "Found " << key << " at index " << index << endl;
    else
        cout << key << " not found in table" << endl;
};
;
int main()
{
    system("cls");
    Hash hash = Hash(10);
    string letters[] = {"c", "bird", "css", "dom", "at", "react", "c#", "hash", "js", "java"};
    hash.insertArray(letters);
    hash.displayHash();

    cout << "\nDelete Item\n";
    hash.deleteItem("c#");
    hash.deleteItem("hash");
    hash.displayHash();

    hash.searchItem("react");
    return 0;
}