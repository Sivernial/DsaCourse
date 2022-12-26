#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

ll gcd(ll n, ll k){
    if(k==0){
        return n;
    }
    return(gcd(k,n%k));
}

ll lcm(ll n, ll k){
    return(n*k/(gcd(n,k)));
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n,k;
        cin>>n>>k;
        
        cout<<lcm(n,k)/k<<endl;

    }
    return 0;
}