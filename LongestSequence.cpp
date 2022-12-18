#include<iostream>
using namespace std;
template<class T>
class Stack{
    public:
    T arr[INT8_MAX];
    int index=0;
    
    void push(T num){
        arr[index]=num;
        index++;
    }
        
        
    void pop(){
        arr[index-1]={};
        index--;
    }
    int sizes()
      {
          return(index);
      }
    
    int isempty(){
        if (index==0){
            return(1);
        }
        else{
            return(0);
        }
    }
    int top(){
        return(arr[index-1]);
    }
};

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

int main(){
    int n;
    Stack<int> s1;
    
    cin>>n;
    int arr[n];
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;
    }
    quickSort(arr,0,n-1);
    int c=0;
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==arr[i+1])
        {
            continue;
        }
        else{
            arr2[c]=arr[i];
            c++;
        }
        
    }
    int counter=0;
    int fix=0;
    printArray(arr2,c);
    for (int i = 0; i < c; i++)
    {
        if (arr[i]==arr[i+1]-1 && fix==0)
        {
            counter++;
            fix++;
        }
        else if (arr[i]==arr[i+1]-1 && fix!=0)
        {
            counter++;
            fix++;
        }
        else if (arr[i]!=arr[i+1]-1 && fix!=0)
        {
            counter++;
            s1.push(counter);
            fix=0;
            counter=0;
        }
        
    }
    if (s1.sizes()==0){
        cout<<1;
        return 0;
    }
    int temp=0;
    while(s1.isempty()!=1){
        if (s1.top()>temp)
        {
           temp=s1.top();
        }
        s1.pop();
        
    }
    cout<<temp;

}