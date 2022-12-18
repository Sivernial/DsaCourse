# include <iostream>
using namespace std;

int main(){
    long n;
    long k;
    cin>>n;
    cin>>k;
    long arr[n];
    long arr1[n];
    long arr2[n];
    int ele;
    for (long i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;
        arr1[i]=0;
        arr2[i]=0;
    }
    for (long i = 0; i < n; i++)
    {
        arr1[arr[i]%n]++;
        arr2[arr[i]*k%n]++;
    }
    long count=0;
    for (long i = 0; i <n; i++)
    {
        if(i==0){
            count+=arr2[0]*arr1[0];
            continue;
        }
        count+=arr2[n-i]*arr1[i];

    }
    cout<<count;
    return 0;    
}