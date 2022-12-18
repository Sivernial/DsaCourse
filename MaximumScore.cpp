#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] <<' ' ;
    cout << endl;
}

int lis(int arr[], int n)
{
    int p1[n / 2];
    int p2[n / 2];
    int switcher = 0;
    int index1 = 0;
    int index2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[n - i] && switcher % 2 == 0)
        {
            p1[index1] = arr[i];
            switcher++;
            index1++;
        }
        else if (arr[i] < arr[n - i] && switcher % 2 == 0)
        {
            p1[index1] = arr[n - i];
            switcher++;
            index1++;
        }
        else if (arr[i] < arr[n - i] && switcher % 2 == 1)
        {
            p2[index2] = arr[n - i];
            switcher++;
            index2++;
        }
        else if (arr[i] > arr[n - i] && switcher % 2 == 1)
        {
            p2[index2] = arr[i];
            switcher++;
            index2++;
        }
    }
    int sum = 0;
    for (int i = 0; i < (n/2)-1; i++)
    {
        if (p2[i+1]>p1[i] && p2[i+1]>p1[i+1])
        {
            int temp;
            temp=p1[i];
            p1[i]=p2[i];
            p2[i]=temp;
            temp=p1[i+1];
            p1[i+1]=p2[i+1];
            p2[i+1]=temp;
            i++;
        }
        
    }
    for (int i = 0; i < n/2; i++)
    {
        sum+=p1[i];
    }
    // printArray(p1,n/2);
    printArray(p2,n/2);
    return sum;
    
    
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
    cout << (lis(arr, n));


    return 0;
}