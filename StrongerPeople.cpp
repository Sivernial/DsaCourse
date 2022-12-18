#include<iostream>
using namespace std;

int mod(int a,int b){
    if (a>b)
    {
        return(a-b);
    }
    else{
        return(b-a);
    }
    
}

int median (int arr[],int n){
    int med=0;
    if(n%2==0){
        med=(arr[n/2]+arr[(n/2)-1])/2;
    }
    else{
        med=arr[((n+1)/2)-1];
    }
    return med;
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
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
    int arr[n];
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        // cout<<"the elements is:"<<ele<<endl;
        arr[i]=ele;
    }
    cin>>k;
    
    // printArray(arr,n);
    
    int arr2[n];
    quickSort(arr,0,n-1);
    int med =median(arr,n);
    cout<<"The median is:"<<med<<endl;
    printArray(arr,n);
    int c1=0;
    int c2=n-1;
    for (int i = 0; i < k; i++)
    {
        if(mod(arr[c1],med)>mod(arr[c2],med)){
            arr2[i]=arr[c1];
            c1++;
        }
        else if(mod(arr[c1],med)<mod(arr[c2],med)){
            arr2[i]=arr[c2];
            c2--;
        }
        else if(mod(arr[c1],med)==mod(arr[c2],med)){
            if(arr[c1]>arr[c2]){
                arr2[i]=arr[c1];
                c1++;
            }
            else{
                arr2[i]=arr[c2];
                c2--;
            }
        }
    }
    quickSort(arr2,0,k-1);
    cout<<"The array 2 is:"<<endl;
    printArray(arr2,k);
    

   
}