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

void inorder(Node* root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if (root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
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

Node* SearchBinaryTree(Node*root,int key){
    if(root==NULL){
        return(NULL);
    }
    if(root->data==key){
        return(root);
    }
    if (root->data>key){
        return(SearchBinaryTree(root->left,key));
    }
    else{
        return(SearchBinaryTree(root->right,key));
    }
}
int main(){
    #ifndef ONLINE_MODE
    freopen("input.txt","r",stdin);
    freopen( "output.txt","w",stdout);
    #endif
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return(0);
    }
