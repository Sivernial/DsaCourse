#include<iostream>
using namespace std;
/*Driver code starts*/
typedef struct Node{
  int data;
  Node *next;
  
}Node;

Node *insert(Node* end, int val){
  Node *n= new Node;
  n->data=val;
  n->next=NULL;
  end->next=n;
  return n;
}

void loopHere(Node *head, Node *tail, int position){
  if(position==0) return;
  Node *walk=head;
  int i=0;
  while(i<position-1){
    walk=walk->next;
    i++;
  }
  // cout<<walk->data<<'\n';
  tail->next=walk;
}
/*Driver code ends*/


Node *solve(Node *head){
    Node *n=new Node;
    Node* arr[INT8_MAX];
    int a = 0, i = 0;
    Node *check = head;
    while(true){
        arr[a++] = check;
        check = check->next;
        i = 0;
        for (i; i < a; i++)
        {
            if(check == arr[i]){
                break;
            }
        }
        if(arr[i] == check){
            break;
        }
    }
    check = arr[a-1];
    for (int j=i;j<a;j++){
        check = insert(check, arr[j]->data);
    }
    return head;
  //your code goes here
  


}


/*Driver code starts*/
int main(){
  int n;cin>>n;
  Node *head= new Node;
  int temp;cin>>temp;
  head->data=temp;
  head->next=NULL;
  Node *end=head;
  for(int i=1;i<n;i++){
    cin>>temp;
    end=insert(end,temp);
  }

  int position;cin>>position;
  loopHere(head,end,position);

  head=solve(head);
  Node *ptr=head;
  
  while(ptr){
    cout<<ptr->data<<' ';
    ptr=ptr->next;
  }
}
/*Driver code ends*/