#include <iostream>
#include <list>
using namespace std;
class Hash
{
    // No. of bucket
    int BUCKET;
    // Create a sequence container from list library type int and set list's name to table
    list<int> *table;

public:
    // Constructor
    Hash(int maxSize);
    // inserts a key into hash table
    void insertItem(int x);
    // inserts a array into hash table
    void insertArray(int arr[]);
    // deletes a key from hash table
    void deleteItem(int key);
    // hash function to map values to key
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    // function to display the hash table
    void displayHash();
    void searchItem(int key);
};
Hash::Hash(int maxSize)
{
    // This constructor initialize max size of the table
    // By set table to the size of BUCKET
    this->BUCKET = maxSize;
    table = new list<int>[BUCKET];
}
void Hash::insertItem(int key)
{
    // Hash the key
    int index = hashFunction(key);
    // Push the key to correspondng index to the end of the list
    table[index].push_back(key);
}
void Hash::insertArray(int *arr)
{
    // travel throw the list size
    for (int i = 0; i <= BUCKET - 1; i++)
    {
        // insert if the element != 0
        if (arr[i] != 0)
            insertItem(arr[i]);
    }
}
void Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    // Iterate each container in list
    list<int>::iterator i;
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
void Hash::searchItem(int key)
{
    int index = hashFunction(key);
    // Iterate each container in list
    list<int>::iterator i;
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
int main()
{
    system("cls");
    Hash hash = Hash(10);
    int arr[] = {20, 11, 12, 23, 0, 5, 0, 17, 8, 9};
    hash.insertArray(arr);
    hash.displayHash();
    cout << "\n------------After Delete-----------\n";
    hash.deleteItem(12);
    hash.displayHash();

    cout << "\n-----------Insert Collision----------- \n";
    hash.insertItem(13);
    hash.insertItem(57);
    hash.displayHash();
    hash.searchItem(57);
    return 0;
}