#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int arr[n];
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    int a = 0;
    for (int i = 0; i < n; i++)
    
    {
        
        a += arr[i];
        
    }
    if (a >= k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
}