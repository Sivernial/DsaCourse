#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
    public:
    T arr[INT8_MAX];
    int index=0;
    
    void push(T num){
        arr[index]=num;
        index++;
    }
        
        
    void pop(){
        arr[index-1]={};
        index--;
    }
    int sizes()
      {
          return(index);
      }
    
    int isempty(){
        if (index==0){
            return(1);
        }
        else{
            return(0);
        }
    }
    int top(){
        return(arr[index-1]);
    }
};



class Queue{
    public:
    Stack<int> s1,s2;
    
    void push(int num){
        s1.push(num);
        }
    void pop(){
        if(s1.isempty()==1 && s2.isempty()==1){
            cout<<"empty"<<endl;
            return;
        }
        else{
            while(s1.isempty()==0){
            s2.push(s1.top());
            s1.pop();
        }
        cout<<s2.top()<<endl;
        s2.pop();

        }
        while(s2.isempty()==0){
            s1.push(s2.top());
            s2.pop();
        }
        
    }

};



int main(){
    Queue s1;
    int n;
    cin>>n;
    string s;
    int ele;
    for (int i=0;i<n;i++){
        cin>>s;
        //cout<<"S is:"<<s<<endl;
        if (s=="pop"){
            s1.pop();
        }
        if (s=="push"){
            cin>>ele;
            s1.push(ele);
        }

	// your code goes here
	
    }
    return 0;
}