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
void Monsters(int array1[],int n){
    Stack<int> s1,s2;
    int arr2[n];
    arr2[0]=0;

    s1.push(0);
    cout<<"left:"<<endl;
    for(int i=1;i<n;i++){
        while(array1[i]>array1[s1.top()] ){    //Left compare
            s1.pop();
            if(s1.isempty()==1){
                break;
            }
        }
        if(s1.isempty()==1){
            cout<<"Adding no:"<<i<<" is :"<<i<<endl;
            arr2[i]=i;
            s1.push(i);

        }
        else{
            
            cout<<"Adding no:"<<i<<" is :"<<i-s1.top()-1<<endl;
            arr2[i]=i-s1.top()-1;
            s1.push(i);
        }
        
        //arr2[i]=i-s1.top();
    }

    s2.push(n-1);
    cout<<"Right"<<endl;
    for(int i=n-2;i>=0;i--){
        while(array1[i]>array1[s2.top()] ){    //Right compare
            s2.pop();
            if(s2.isempty()==1){
                break;
            }
        }
        if(s2.isempty()==1){
            cout<<"Adding no:"<<i<<" is :"<<n-i-1<<endl;
            arr2[i]+=n-i-1;
            s2.push(i);

        }
        else{
            
            cout<<"Adding no:"<<i<<" is :"<<s2.top()-i-1<<endl;
            arr2[i]+=s2.top()-i-1;
            s2.push(i);
        }
        
    }
    
    for (int j=0;j<n;j++){
        cout<<arr2[j]<<" ";
    }



}

int main(){
    int n;
    cin>>n;
    if(n==0){
        return 0;
    }
    int input[n];
    for ( int i=0 ;i<n;i++){
        int ele;
        cin>>ele;
        input[i]=ele;

    }
    Monsters(input,n);
    
}
