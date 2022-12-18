#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int arr[INT8_MAX];
    int top=0;
    int rear=0;
    int size=rear-top;
    
    void push(int num){
        size=rear-top;
        /*if(rear==2147483647){
            rear=0;
        }*/
        if(size==0){
            arr[top]=num;
            rear++;
            //cout<<"Arr top is:"<<arr[top]<<endl;
        }
        else{
            arr[rear]=num;
            rear++;
            
        }
        
    }
        
    int pop(){
        size=rear-top;
        if (size==0){
            cout<<"queue is empty"<<endl;
        }
        else{
            return(arr[top]);
            arr[top]={};
            top++;
        }
        
    }
    void front(){
        size=rear-top;
    	if (size==0){
    		cout<<(-1)<<endl;
    	}
    	else{
    		cout<<(arr[top])<<endl;
    	}
    }
    void back(){
        size=rear-top;
    	if (size==0){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<arr[rear-1]<<endl;
    	}
    }
    void sizes()
      {
          cout<< (rear-top)<<endl;
      }
    
    void isempty(){
        if (size==0){
            cout<<(1)<<endl;
        }
        else{
            cout<<(0)<<endl;
        }
    }
};
int main() {
    int n;
    cin>>n;
    int ele;
    string s;
    Queue s1;
    for (int i=0;i<n;i++){
        cin>>s;
        //cout<<"S is:"<<s<<endl;
        if (s=="pop"){
            s1.pop();
        }
        if (s=="push"){
            cin>>ele;
            //cout<<"The ele:"<<ele<<endl;
            s1.push(ele);
            //cout<<"Next command"<<endl;
        }
        if (s=="front"){
            s1.front();
        }
        if(s=="size"){
            s1.sizes();
        }
        if (s=="isempty"){
            s1.isempty();
        }
        if (s=="back"){
            s1.back();
        }
	// your code goes here
	
    }
    return 0;
}

