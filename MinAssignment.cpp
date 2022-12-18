#include <iostream>
using namespace std;


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[],int arr2[],int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
            swap(&arr2[i], &arr2[j]);
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    swap(&arr2[i + 1], &arr2[high]);
    return (i + 1); 
} 
  

void quickSort(int arr[],int arr2[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr,arr2, low, high); 
        quickSort(arr,arr2, low, pi - 1); 
        quickSort(arr,arr2, pi + 1, high); 
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
    int n;
    cin>>n;
    int r;
    cin>>r;
    int a;
    cin>>a;
    int arr1[n];
    int arr2[n];
    int total_grade=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
        total_grade+=arr1[i];
        cin>>arr2[i];
    }
    quickSort(arr2,arr1,0,n-1);
    printArray(arr2,n);
    printArray(arr1,n);
    int count=0;
    int grade_rec=(a*n)-total_grade;
    int index=0;
    // if (grade_rec<0)
    // {
    //     cout<<0;
    //     return 0;
    // }
    
    
    
    while (grade_rec>0)
    {
        if (arr1[index]==r)
        {
            index++;
        }
        
        else {
            grade_rec=grade_rec-1;
            arr1[index]++;
            count=count+arr2[index];

        }
    }
    if (n%2==1 && r==a)
    {
        cout<<count-1;
        return 1;
    }
    cout<<count;
    
    
}