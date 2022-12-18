#include<iostream>
using namespace std;

void CountingSort(long arr[],long max,long n,long min){
    int k = max - min + 1;
    long arr2[max-min+1];
    for (int i = 0; i < k; i++)
    {
        arr2[i]=0;
    }
    for(int i = 0;i<n;i++){
        arr2[arr[i]-min]++;
    }
    
    for(int i = 0;i<k;i++){
        for(int j = 0;j<arr2[i];j++){
            cout<<i+min<<" ";
        }
    }
}


int main(){
    long n;
    cin>>n;
    long arr[n];
    long ele;
    long max=0;
    long min=100000;
    for (long i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;
        if (max<ele)
        {
            max=ele;
        }
        if (min>ele)
        {
            min=ele;   
        }
        
        
    }
    //cout<<"The min is:"<<min<<endl;
    
    CountingSort(arr,max,n,min);
    
}