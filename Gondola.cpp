#include<iostream>
using namespace std;

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[],int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
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
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void Gondola(int arr [],int n,int x){
    int c1=0;
    int c2=n-1;
    int counter =0;
    while ((c1<c2))
    {
        if (arr[c1]+arr[c2]>x)
        {
            c2--;
        }
        else if (arr[c1]+arr[c2]<=x)
        {
            c1++;
            c2--;
            counter++;
        }
        
        
    }
    counter=counter+(n-(2*counter));
    cout<<counter;
    
}

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        arr[i]=ele;
    }
    quickSort(arr,0,n-1);
    Gondola(arr,n,x);
    
}