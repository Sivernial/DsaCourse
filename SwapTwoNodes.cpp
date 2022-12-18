#include<iostream>      
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;     //Constructor
        next=NULL;
    }
};
void display(node* head){ //Directly taking value as no changes are going to be made.
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next; 
    }
    cout<<endl;

}
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
int main(){
    #ifndef ONLINE_MODE
    freopen("input.txt","r",stdin);
    freopen( "output.txt","w",stdout);
    #endif
    node* head=NULL;
    int n;
    cin>>n;
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        TailInsert(head,ele);
    }
    display(head);
    int a,b;
    cin>>a;
    cin>>b;
    if (a>n || b>n){
        cout<<-1;
        return -1;
    }
    node* temp1=head;
    node* temp2=head;
    int temp;
    for (int i = 0; i < a-1; i++)
    {
        temp1=temp1->next;
        
    }
    //cout<<temp1->data<<endl;;
    for (int i = 0; i < b-1; i++)
    {
        temp2=temp2->next;
    }
    temp=temp1->data;
    temp1->data=temp2->data;
    temp2->data=temp;
    //cout<<"Temp is:"<<temp<<endl;
    display(head);
    return 0;
}
