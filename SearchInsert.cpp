#include<iostream>
using namespace std;

int BinarySearch(int arr[],int low,int high,int mid,int key){
    int temp=mid;
    int mid2=(low+high)/2;
    if (mid2==temp)
    {
        return(high);
    }
    
    // cout<<"Mid is:"<<mid2<<endl;
    if (arr[mid2]==key){
        return(mid2);
    }
    else if(key<arr[mid2]){
        return(BinarySearch(arr,low,mid2,mid2,key));
    }
    else{
        return(BinarySearch(arr,mid2,high,mid2,key));
    }
    return(high);
}

int main(){
    int n;
    cin>>n;
    int ele;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;
    }
    int key;
    cin>>key;
    cout<<BinarySearch(arr,0,n,0,key);
}