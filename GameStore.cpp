#include<iostream>
using namespace std;


void GameStore(int price[],int budget[],int m){
    int counter=0;
    int index=0;
    for (int i = 0; i < m; i++)
    {
        while (price[index]<budget[i])
        {
            counter++;
            budget[i]=budget[i]-price[index];
            index++;
        }
        index=0;
        cout<< counter<<" ";
        counter=0;
        
    }
    
    
}

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int prices[n];
    int budget[m];
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        prices[i]=ele;
    }
     for (int i = 0; i < m; i++)
    {
        cin>>ele;
        budget[i]=ele;
    }
    GameStore(prices,budget,m);
}