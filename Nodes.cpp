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

void HeadInsert(node* &head,int val){
    node* n=new node(val);
    node* temp= head;
    n->next=temp;
    head=n;
}
void Deletion(node* head,int val){
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }



void display(node* head){ //Directly taking value as no changes are going to be made.
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next; 
    }
    cout<<"NULL"<<endl;

}
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;

}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL ;
    return newhead;
}

node* reverseK(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
    head->next=reverseK(nextptr,k);
    }
    return prevptr;
}

int length(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return(count);
}

void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int intersection(node* head1,node* head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node* ptr1; //points to the linked list of longer length
    node* ptr2;//points to the linked list of shorter length
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1=ptr1->next;
        if(ptr1=NULL){
            return(-1);
        }
        d--;
          
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if (ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }
    return(-1);
}
node* DeleteMid(node* &head){ // Not using length
    if(head==NULL){
        return NULL;
    }
    if (head->next==NULL)
    {
        head=NULL;
        return NULL;
    }
    node* ptr_fast=head;
    node* ptr_slow=head;
    node* pre;
        while(ptr_fast!=NULL && ptr_fast->next!=NULL){
            ptr_fast=ptr_fast->next->next;
            pre=ptr_slow;
            ptr_slow=ptr_slow->next;
        }
        pre->next=ptr_slow->next;
        ptr_slow=NULL;
        return head;
    }




int main(){
    #ifndef ONLINE_MODE
    freopen("input.txt","r",stdin);
    freopen( "output.txt","w",stdout);
    #endif
    node* head1=NULL;
    node* head2=NULL;
    cout<<"Heloo"<<endl;
    TailInsert(head1,1);
    TailInsert(head1,2);
    TailInsert(head1,3);
    TailInsert(head1,4);
    TailInsert(head1,5);
    TailInsert(head1,6);
    TailInsert(head2,9);
    TailInsert(head2,10);
    intersect(head1,head2,3);
    display(head1);
    display(head2);
    cout<<intersection(head1,head2);
    return(0);
}  
