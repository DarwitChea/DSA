#include <iostream>
using namespace std;

void swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int first_ind, int last_ind, int pivot)
{
    int i = first_ind;
    int j = first_ind;
    while (i <= last_ind)
    {
        if (arr[i] > pivot)
        {
            i++;
        }
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSort(int arr[], int first_ind, int last_ind)
{
    if (first_ind < last_ind)
    {
        int pivot = arr[last_ind];
        int pos = partition(arr, first_ind, last_ind, pivot);

        quickSort(arr, first_ind, pos - 1);
        quickSort(arr, pos + 1, last_ind);
    }
}

int main()
{
    int arr[] = {8, 15, 4, 3, 18, 7, 1, 4};
    int first_ind = 0;
    int last_ind = 7;
    int pivot = arr[last_ind];


    partition(arr, 0, 7, 4);
    quickSort(arr, 0, 7);

    for (int i = 0; i <= 7; i++)
    {
        cout << arr[i] << " ";
    }
}