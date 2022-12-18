#include <iostream>
using namespace std;
int max_outTime=0;
int min_inTime=100;

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

void input(int in_time[],int out_time[],int n_group[],int n){
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        in_time[i]=ele;
        if (ele<min_inTime)
        {
            min_inTime=ele;
        }        
        cin>>ele;
        out_time[i]=ele;
        if (ele>max_outTime)
        {
            max_outTime=ele;
        }
        cin>>ele;
        n_group[i]=ele;
    }
        
}

int footfall=0;
int max_foot=0;
void AddSub(int in_time[],int out_time[],int n1_group[],int n2_group[]){
    int c1=0;
    int c2=0;
    for (int i = min_inTime; i <=max_outTime; i++)
    {
        while (i==out_time[c2])
        {
            footfall=footfall-n2_group[c2];
            c2++;
        }
        while (i==in_time[c1])
        {
            footfall+=n1_group[c1];
            c1++;
            //cout<<footfall<<" ";
            if (max_foot<footfall)
            {
                max_foot=footfall;
            }
            
        }
    }          
}


int main(){
    // #ifndef ONLINE_MODE
    // freopen("input.txt","r",stdin);
    // freopen( "output.txt","w",stdout);
    // #endif
    int n;
    cin>>n;
    int in_time[n];
    int out_time[n];
    int n_group[n];
    int n2_group[n];
    input(in_time,out_time,n_group,n);
    for (int i = 0; i < n; i++)
    {
        n2_group[i]=n_group[i];
    }
    quickSort(in_time,n_group,0,n);
    quickSort(out_time,n2_group,0,n);
    //cout<<"the max out time is:"<<max_outTime<<endl;
    // printArray(out_time,n);
    // printArray(in_time,n);
    // printArray(n_group,n);
    // printArray(n2_group,n);
    AddSub(in_time,out_time,n_group,n2_group);
    //cout<<"The min in time is"<<min_inTime<<endl;
    cout<<"The max footfall is"<<max_foot;
}