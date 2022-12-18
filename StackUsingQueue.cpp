#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int arr[INT8_MAX];
    int top=0;
    int rear=0;
    int size=0;
    
    int push(int num){
        size=rear-top;
        if(size==0){
            top=0;
            rear=0;
            arr[top]=num;
            rear++;
            size=rear-top;
           // cout<<"New size is"<<size<<endl;
        }
        else if (size!=0){
            //cout<<"Old size is:"<<size<<endl;
            arr[rear]=num;
            rear++;
            size=rear-top;
            /*cout<<"The later element is:"<<arr[rear]<<endl;
            cout<<"Rear is:"<<rear<<endl;

            cout<<"New size is"<<size<<endl;*/
            
        }
        
    }
        
    void pop(){
        size=rear-top;
        if (size==0){
            cout<<"queue is empty"<<endl;
        }
        else{
            //cout<<"The popped ele is:"<<arr[top]<<endl;
            arr[top]={};
            top++;
            size=rear-top;
        }
        
    }
    int front(){
        size=rear-top;
    	if (size==0){
    		return(-1);
    	}
    	else{
    		return(arr[top]);
    	}
    }
    int back(){
        size=rear-top;
    	if (size==0){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<arr[rear-1]<<endl;
    	}
    }
    int sizes()
      {
          cout<<rear-top<<endl;
      }
    
    int isempty(){
        if (size==0){
            return(1);
        }
        else{
            return(0);
        }
    }
};
















class Stack{
  
  public:
  Queue q1,q2;
      int Push(int x)
      {
          q2.push(x);
          while (q1.isempty()!=1) {
              q2.push(q1.front());
              q1.pop();
          }
          Queue q;
          q1 = q2;
          q2 = q;
          //cout<<"Back q1 is"<<q1.back()<<endl;
          //cout<<"Back q2 is"<<q2.back()<<endl;
      }
   
      void pop()
      {
          q1.pop();
      }
      int top()
    {
        if (q1.isempty()==1)
            cout<< -1<<endl;
        else{
            cout<<q1.front()<<endl;;

        }
        
    }
    int Isempty(){
        q1.isempty();
    }
    int Size(){
        q1.sizes();
    }
      
  };


int main() {
    int n;
    cin>>n;
    int ele;
    string s;
    Stack s1;
    for (int i=0;i<n;i++){
        cin>>s;
        cout<<"S is:"<<s<<endl;
        if (s=="pop"){
            s1.pop();
        }
        if (s=="push"){
            cin>>ele;
            s1.Push(ele);
        }
        if (s=="peek"){
            s1.top();
        }
        if(s=="size"){
            s1.Size();
        }
        if (s=="isempty"){
            s1.Isempty();
        }
	// your code goes here
	
    }
    return 0;
}
