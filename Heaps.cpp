#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i)
{
    int maxInd = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[maxInd])
    {
        maxInd = l;
    }
    if (r < n && arr[r] > arr[maxInd])
    {
        maxInd = r;
    }
    if (maxInd != i)
    {
        swap(arr[i], arr[maxInd]);
        heapify(arr, n, maxInd);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}