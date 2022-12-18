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
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
  
int partition (int arr2[],int arr3[],int low, int high) 
{ 
    double pivot = arr2[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr2[j] < pivot) 
        { 
            i++; 
            // swap2(&arr[i], &arr[j]); 
            swap(&arr2[i], &arr2[j]);
            swap(&arr3[i], &arr3[j]);
        } 
    } 
    // swap2(&arr[i + 1], &arr[high]); 
    swap(&arr2[i + 1], &arr2[high]);
    swap(&arr3[i + 1], &arr3[high]);
    return (i + 1); 
} 
  

void quickSort(int arr2[],int arr3[],int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr2,arr3, low, high); 
        quickSort(arr2,arr3, low, pi - 1); 
        quickSort(arr2,arr3, pi + 1, high); 
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
    // quickSort(weight,value,0,n-1);
    // // printArray(ratio,n);
    // printArray2(weight,n);
    // printArray2(value,n);

    int bag;
    cin>>bag;

    double total=0.0;
    for (int i =n-1; i >= 0; i--)
    {
        if (bag<weight[i])
        {
            // total+=((bag)*(ratio[i]));
            continue;
        }
        else{
            total+=value[i];
            // bag=bag-weight[i];
        }
        // cout<<"The bag is:"<<bag<<endl;

        
    }
    ll Matrix [n+1][bag+1];
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=bag; j++)
        {
            if (i==0 || j==0)
            {
                Matrix[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                int sum=j-weight[i-1];
                Matrix[i][j]=max(value[i-1]+Matrix[i-1][sum],Matrix[i-1][j]);
            }
            else if(weight[i-1]>j)
            {
                Matrix[i][j]=Matrix[i-1][j];
            } 
        }    
    }
    int final_value=Matrix[n][bag];
    cout<<final_value<<endl;
    
    

    
    return 0;
}