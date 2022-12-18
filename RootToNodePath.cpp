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
void preorder(Node* root){
    if (root==NULL){
        return;
    }    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
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
int arr[100000];
int j=0;
Node* SearchInBST(Node*root,int key,int n){
    if(root==NULL){
        arr[j]=-1;
        cout<<arr[j];
        return(NULL);
    }
    if(root->data==key){
        arr[j]=root->data;
        //cout<<(arr[j])<<" ";
        for(int i=0; i<=j ;i++){
            cout<<arr[i]<<" ";
        }
        return(root);
    }
    if (root->data>key){
        arr[j]=(root->data);
        //cout<<(arr[j])<<" ";
        j++;
        return(SearchInBST(root->left,key,n));
    }
    else{
        arr[j]=(root->data);
        //cout<<(arr[j])<<" ";
        j++;
        return(SearchInBST(root->right,key,n));
    }
}

int main(){
    /*#ifndef ONLINE_MODE
    freopen("input.txt","r",stdin);
    freopen( "output.txt","w",stdout);
    #endif
    cout<<"hello"<<endl;*/
    int n,q;
    cin>>n;
    cin>>q;
    int first;
    cin>>first;
    Node* root=new Node(first);
    int val;
    for (int i = 0; i < n-1; i++)
    {
        cin>>val;
        Build(root,val);
    }
    //preorder(root);
    int item;   
    for (int i = 0; i <q; i++)
    {
        cin>>item;
        SearchInBST(root,item,n);
        j=0;
        cout<<endl;
    
    }
}