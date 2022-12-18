#include<iostream>
using namespace std;
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
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int ele;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;

    }
    quickSort(arr,0,n);
    if (n==1 && k!=arr[0])
    { cout<<0;
        return 0;
    }
    if (n==1 && k==arr[0])
    {
        cout<<1;
        return 1;
    }
    printArray(arr,n);
    
    int sum=arr[0]+arr[n-1];
    int c1=0;
    int c2=n-1;
    while (sum!=k)
    {
        cout<<"The sum is:"<<sum<<endl;
        if (c1==n-1)
        {
            break;
        }
        if (sum<k)
        {
            c2=n-1;
            c1++;
        }
        
        c2--;
        sum=arr[c1]+arr[c2];
        
    }
    if (sum==k)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    
    

    
}