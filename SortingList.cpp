#include<iostream>
using namespace std;
    void merge(int arr[], int l, int mid, int r)
    {
        int i = l ;        
        int j = mid + 1;   
        int f = l ;        
        int temp[100000] ; 

        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) {
                temp[f] = arr[i]  ;
                i++ ;
            }
            else {
                temp[f]=arr[j];
                j++;
            }
            f++;
        }
        if (i>mid) {
            while (j<=r) {
                temp[f]=arr[j];
                f++;
                j++;
            }
        }
        else {
            while (i<= mid) {
                temp[f]=arr[i]  ;
                f++ ; 
                i++ ;
            }
        }
        for (int f=l;f<=r;f++) {
            arr[f] = temp[f] ;
        }
    }


    void mergeSort(int arr[],int l,int r)
    {
        if (l<r) {
            int mid=(l+r) / 2 ;
            mergeSort(arr,l,mid)  ;  
            mergeSort(arr,mid+1,r)  ; 
            merge(arr,l,mid,r)  ;  
        }
    }
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;     //Constructor
        next=NULL;
    }
};

void TailInsert(node* &head,int val ){ //&head to get the value by reference.Head already stores the address of the first node and &head stores the address of the address of head.
    node* n=new node(val);  
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){  //to traverse the array.
        temp=temp->next;
    }
    temp->next=n;

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
    int arr[n];
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i]=ele;
    }
    mergeSort(arr,0,n-1);
    printArray(arr,n);

    
 }