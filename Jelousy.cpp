#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int x, y;
        cin >> x;
        cin >> y;
        int arr[n];
        int z = x;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        quickSort(arr, 0, n - 1);
        for (int j = 0; j < n; j++)
        {
            if (y%arr[j]==0)
            {
                z=z*arr[j];
                z=z%100000;
            }
            
        }
        if (z == y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}