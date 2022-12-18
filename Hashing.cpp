#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] <<' ' ;
    cout << endl;
}
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll m;
    ll count=0;
    for (ll i = 0; i < n; i++)
    {
        arr[i]=-1;
        
    }
    for (ll i = 0; i < m; i++)
    {
        int ele;
        cin>>ele;
        if (arr[ele%n]==-1)
        {
            arr[ele%n]=ele;
        }
        else{
            count++;
        }
        
    }
    cout<<count;
    
    
    return 0;
}