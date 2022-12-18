#include<iostream>      
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};
int i=0;


Node* Build(Node* root,int val){
    if(root==NULL){
        return(new Node(val));
    }
    if(val>root->data){
        root->right=Build(root->right,val);
    }
    else{
        root->left=Build(root->left,val);
    }
    return root;
}
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}
void inorder(Node* root,int arr[]){
    if (root==NULL){
        return;
    }
    inorder(root->right,arr);
    arr[i]=root->data;
    i++;
    inorder(root->left,arr);
}



int main(){
    int n;
    cin>>n;
    int ele;
    cin>>ele;
    Node* root=new Node(ele);
    for (int i = 0; i < n-1; i++)
    {
        cin>>ele;
        Build(root,ele);
        //cout<<ele;
    }
    int arr[n];
    inorder(root,arr);
    int k;
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        cout<<arr[i]<<" ";
    }
    
       
}