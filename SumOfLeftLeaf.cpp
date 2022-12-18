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
int SumOfLeaf(Node *root)
{
    int out = 0;
    if(root == NULL){
        return out;
    }
    if (root != NULL)
    {
        if(root->left != NULL){
            if (root->left->left == NULL && root->left->right == NULL){
                out += root->left->data;
            }
        }
        else{
            out += SumOfLeaf(root->left);
        }
        out += SumOfLeaf(root->right);
    }
    return out;
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

int main(){
    // #ifndef ONLINE_MODE
    // freopen("input.txt","r",stdin);
    // freopen( "output.txt","w",stdout);
    // #endif
    //cout<<"hellow"<<endl;
    int n;
    cin>>n;
    int first;
    cin>>first;
    Node* root=new Node(first);
    for (int i = 0; i <n-1; i++)
    {
        int val;
        cin>>val;
        root = Build(root,val);
    }
    cout<<SumOfLeaf(root)<<endl;
    return(0);
}
