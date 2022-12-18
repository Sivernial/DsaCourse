#include<iostream>
using namespace std;

void SkipSearch(int arr[],int n,int k){
    int skip=2;
    int flag=0;
    for (int i = 0; i < n; i+=skip)
    {
        if (arr[i]==k)
        {
            cout<<i<<endl;
            break;
        }
        else if (arr[i]>k && flag==0)
        {
            i-=3;
            flag=1;
        }
        else
        {
            continue;
        }
    }
    cout<<-1<<endl;
    
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    SkipSearch(arr,n,k);
    
}