#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printArray(double arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] <<' ' ;
    cout << endl;
}
void printArray2(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] <<' ' ;
    cout << endl;
}

void swap2(double* a, double* b) 
{ 
    double t = *a; 
    *a = *b; 
    *b = t; 
} 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
  
int partition (double arr[],int arr2[],int arr3[],int low, int high) 
{ 
    double pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap2(&arr[i], &arr[j]); 
            swap(&arr2[i], &arr2[j]);
            swap(&arr3[i], &arr3[j]);
        } 
    } 
    swap2(&arr[i + 1], &arr[high]); 
    swap(&arr2[i + 1], &arr2[high]);
    swap(&arr3[i + 1], &arr3[high]);
    return (i + 1); 
} 
  

void quickSort(double arr[],int arr2[],int arr3[],int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr,arr2,arr3, low, high); 
        quickSort(arr,arr2,arr3, low, pi - 1); 
        quickSort(arr,arr2,arr3, pi + 1, high); 
    } 
} 

int main()
{
    ll n;
    cin>>n;
    int weight[n];
    int value[n];
    double ratio[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
        
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
        
    }
     for(int i=0;i<n;i++){
        ratio[i]=(double)value[i]/(double)weight[i];
        
    }
    quickSort(ratio,value,weight,0,n-1);
    // printArray(ratio,n);
    // printArray2(weight,n);
    // printArray2(value,n);

    int bag;
    cin>>bag;

    double total=0.0;
    for (int i = n-1; i >=0; i--)
    {
        if (bag<weight[i])
        {
            total+=((bag)*(ratio[i]));
            break;
        }
        else{
            total+=value[i];
            bag=bag-weight[i];
        }


        
    }
    cout<<(int)total;
    

    
    return 0;
}