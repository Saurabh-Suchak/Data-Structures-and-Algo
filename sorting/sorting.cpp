#include <iostream>
using namespace std;

void swap(int *a, int *b) // swapping using pointers avoids copying large amt of memory
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubblesort(int arr[], int n)

{
    bool swapped;
    int i, j;
    for (i = 0; i < n - 1; i++) // no of iterations
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) // swapping adjacent in each iteration
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped = false)
        {
            break;
        }
    }
    display(arr, n);
}

/*
void bubbleSort(int arr[], int n)
{
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort.
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);

    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, n-1);
}
*/

void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    display(arr, n);
}

// there is also binary insertion sort

int main()
{
    int choice;
    int arr[] = {74, 93, 12, 56, 9, 37};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "choose the operation- \n";
    cout << "1. display the array\n";
    cout << "2. bubble sort\n";
    cout << "3. insertion sort\n";

    cin >> choice;
    switch (choice)
    {
    case 1:
        display(arr, n);
        break;
    case 2:
        bubblesort(arr, n);
        break;
    case 3:
        insertionsort(arr, n);
        break;
    default:
        cout << "invalid choice entered";
    }
}