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


void Duplicate(int arr[],int n){
    int counter=0;
    int c2=0;
    int arr2[n];
    while (counter<n-2)
    {
        if (arr[counter]==arr[counter+2] && arr[counter]==arr[counter+1])
        {
           // cout<<"c2 is:"<<c2<<endl;
            //cout<<"The element is"<<arr[counter+1]<<" ";
            if (c2==0)
            {
                arr2[c2]=arr[counter];
                counter=counter+3;
                c2++;
            }
            else if (arr[counter]!=arr2[c2-1])
            {
                arr2[c2]=arr[counter];
                counter=counter+3;
                c2++;
            }
            else{
                counter=counter+3;
            }
            
            
        }
        else{
            counter++;
        }
        
    }
    printArray(arr2,c2);
    
    
}
 

 int main(){
    int n;
    cin>> n;
    int arr[n];
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;
    }
    quickSort(arr,0,n);
    //printArray(arr,n);
    Duplicate(arr,n);

    
 }