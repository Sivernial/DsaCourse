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

void MEX(int arr[],int n){
    int val=0;
    for (int i = 0; i < n; i++)
    {
        if (val==arr[i])
        {
            val++;
            continue;
        }
        else{
            cout<<val;
            return;
        }
        
    }
}

int main(){
    int n;
    cin>>n;
    int ele;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>ele;
        arr[i]=ele;
    }
    quickSort(arr,0,n-1);
    MEX(arr,n);
    
}