#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
    public:
    T arr[INT8_MAX];
    int index=0;
    int min;
    
    void push(T num){
        //cout<<"Pushed"<<endl;
        arr[index]=num;
        if (index==0){
            min=arr[index];
        }
        else{
            if(min>arr[index]){
                min=arr[index];
            }
        }
        index++;
        
    }
        
        
    void pop(){
        if(index==0){
            cout<<-1<<endl;;
        }
        else{
            arr[index-1]={};
            index--;
        }
        
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
    void top(){
        //cout<<"index is:"<<index<<endl;
        if(index==0){
            cout<<(-1)<<endl;;
        }
        else{
            cout<<(arr[index-1])<<endl;
        }
        
    }
    void getmin(){
        if(index!=0){
            cout<<(min)<<endl;
        }
    }
};

int main(){
    #ifndef ONLINE_MODE
    freopen("input.txt","r",stdin);
    freopen( "output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int ele;
    string s;
    Stack<int> s1;
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
        if(s=="size"){
            s1.sizes();
        }
        if (s=="isempty"){
            s1.isempty();
        }
        if (s=="getmin"){
            s1.getmin();
        }
        if (s=="top"){
            s1.top();
        }
	// your code goes here
	
    }
}

