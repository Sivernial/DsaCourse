#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n)
{
    int LIS[n];
    LIS[0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        LIS[i] = 1;
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j])
                LIS[i] = max(LIS[i], LIS[j] + 1);
    }

    return *max_element(LIS, LIS + n);
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