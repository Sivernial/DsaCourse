#include <iostream>
using namespace std;
int path1[INT16_MAX];
int path2[INT16_MAX];
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root, int arr[])
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, arr);
    cout << root->data << " ";
    inorder(root->right, arr);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
Node *Build(Node *root, int val)
{
    if (root == NULL)
    {
        return (new Node(val));
    }
    if (val > root->data)
    {
        root->right = Build(root->right, val);
    }
    else
    {
        root->left = Build(root->left, val);
    }
    return root;
}

Node *SearchBinaryTree1(Node *root, int key, int c)
{
    if (root == NULL)
    {
        return (NULL);
    }
    if (root->data == key)
    {
        path1[c] = root->data;
        return (NULL);
    }
    if (root->data > key)
    {
        path1[c] = root->data;
        c++;
        return (SearchBinaryTree1(root->left, key, c));
    }
    else
    {
        path1[c] = root->data;
        c++;
        return (SearchBinaryTree1(root->right, key, c));
    }
}
Node *SearchBinaryTree2(Node *root, int key, int c)
{
    if (root == NULL)
    {
        return (NULL);
    }
    if (root->data == key)
    {
        path2[c] = root->data;
        return (NULL);
    }
    if (root->data > key)
    {
        path2[c] = root->data;
        c++;
        return (SearchBinaryTree2(root->left, key, c));
    }
    else
    {
        path2[c] = root->data;
        c++;
        return (SearchBinaryTree2(root->right, key, c));
    }
}
void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    // cout<<(2^3^2);
    int n;
    cin >> n;
    int arr[n];
    int ele;
    cin >> ele;
    arr[0] = ele;
    Node *head = new Node(ele);

    for (int i = 1; i < n; i++)
    {

        cin >> ele;
        Build(head, ele);
        arr[i] = ele;
    }
    // cout<<"The root is:"<<head->data<<endl;
    int temp[n];
    int q;
    cin >> q;
    // preorder(head);
    int a, b;
    for (int i = 0; i < q; i++)
    {
        for (int k = 0; k < n; k++)
        {
            path1[k]=0;
            path2[k]=0;
            temp[k]=0;

        }
        
        cin >> a;
        cin >> b;
        int c1 = 0;
        SearchBinaryTree1(head, arr[a], c1);
        
        c1 = 0;

        SearchBinaryTree2(head, arr[b], c1);
        
        
        int lca;
        int index;

        for (int j = 0; j < n; j++)
        {
            if (path1[j] != path2[j])
            {
                index = j - 1;
                lca = path1[j - 1];
                break;
            }
        }
        // cout<<"The PAth1 is:"<<endl;
        // printArray(path1,n);
        // cout<<"The PAth2 is:"<<endl;
        // printArray(path2,n);
        // cout << "The index :" << index << endl;
        int c2 = 0;
        for (int j = index; j < n; j++)
        {
            if (path1[j]==0)
            {
                break;
            }
            
            temp[c2] = path1[j];
            c2++;
        }
        for (int j = index + 1; j < n; j++)
        {
            if (path2[j]==0)
            {
                break;
            }
            temp[c2] = path2[j];
            c2++;
        }
        // cout<<"Temp is:"<<endl;
        // printArray(temp,n);
        int total = temp[0];
        for (int j = 1; j < n; j++)
        {
            if (temp[j]!=0)
            {
                total = temp[j] ^ total;
            }
            
            
        }
        // cout<<"The LCA is:"<<lca<<endl;
        total = total ^ lca;
        cout << total << endl;
        
    }
}