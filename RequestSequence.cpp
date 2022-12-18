#include<iostream>
using namespace std;

void CountingSort(long arr[],long max,long n,long min,long temp[]){
    int k = max - min + 1;
    long arr2[max-min+1];
    for (int i = 0; i < k; i++)
    {
        arr2[i]=0;
    }
    for(int i = 0;i<n;i++){
        arr2[arr[i]-min]++;
    }
    long index=0;
    for(int i = 0;i<k;i++){
        for(int j = 0;j<arr2[i];j++){
            temp[index]=i+min;
            index++;
        }
    }
}

int BinarySearch(long arr[],int low,int high,int mid,int key){
    int temp=mid;
    int mid2=(low+high)/2;
    if (mid2==temp)
    {
        return(-1);
    }
    
    //cout<<"Mid is:"<<mid2<<endl;
    if (arr[mid2]==key){
        return(mid2);
    }
    else if(key<arr[mid2]){
        return(BinarySearch(arr,low,mid2,mid2,key));
    }
    else{
        return(BinarySearch(arr,mid2,high,mid2,key));
    }
    return(-1);
}


void Request(long arr[],int key,long n,string comm){
    int pos1=BinarySearch(arr,0,n,0,key);
    //cout<<"The index is:"<<pos1<<endl;
    if (comm=="UP")
    {
        for (int i = pos1; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        for (int i = pos1-1; i>=0; i--)
        {
            cout<<arr[i]<<" ";/* code */
        }
        
    }
    else{
        for (int i = pos1; i>=0; i--)
        {
            cout<<arr[i]<<" ";/* code */
        }
        for (int i = pos1+1; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    
}



void printArray(long arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
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
    long temp[n];
    int k;
    cin>>k;
    string s;
    cin>>s;
    CountingSort(arr,max,n,min,temp);
    // printArray(temp,n);
    Request(temp,k,n,s);
    
}