#include<iostream>
using namespace std;
void printArray(long arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void swap(long* a, long* b) 
{ 
    long t = *a; 
    *a = *b; 
    *b = t; 
} 
  
long partition (long arr[],long low, long high) 
{ 
    long pivot = arr[high];
    long i = (low - 1); 
  
    for (long j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 

        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
 
    return (i + 1); 
} 
  

void quickSort(long arr[], long low, long high) 
{ 
    if (low < high) 
    { 
        long pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main(){
    long n;
    cin>>n;
    long arr[n];
    long temp[n];
    long ele;
    for (long i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;
        temp[i]=ele;
    }
    quickSort(temp,0,n-1);
    long counter1=-1;
    long counter2=-1;
    for (long i = 0; i < n; i++)
    {
        if (arr[i]!=temp[i] && counter1==-1)
        {
            counter1=i;
        }
        else if(arr[i]!=temp[i]){
            counter2 = i+1;
        }
        // else if (arr[i]==temp[i] && counter1>=0 && counter2==-1)
        // {
        //     counter2=i; 
        // }
        // if (i==n-1 && counter2==-1 )
        // {
        //     counter2=i+1;
        // }
        // cout<<"Count1 is:"<<counter1<<endl;
        // cout<<"Count2 is:"<<counter2<<endl;
        
    }
    if (counter1==-1)
    {
        cout<<-1;
    }
    else{
        cout<<counter2-counter1;
    }
    
    
    
}