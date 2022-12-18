#include<iostream>
typedef long long int ll;
using namespace std;
template <class T>

class Queue{
    T* arr;
    ll back = -1;
    ll front = 0;
    ll currsize = 0;
    public:
        Queue(){
            arr = new T[INT16_MAX];
        }
        bool isempty(){
            if(currsize==0){
                return true;
            }
            else{
                return false;
            }
        }
        void push(T val){
            if(currsize<=INT16_MAX){
                back++;
            }
            if(back>=INT16_MAX){
                back = 0;
            }
            arr[back] = val;
            currsize++;
            return;
        }
        void pop(){
            if(!isempty()){
                currsize--;
                front++;
                return;
            }
            return;
        }
        T Front(){
            return arr[front];
        }
};

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int M[n][n];
    string atri[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j]=0;
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        M[a-1][b-1]=1;
    }
    Queue<int> q1;
    for (int i = 0; i < n; i++)
    {
        atri[i]="WHITE";
    }

    q1.push(0);
    atri[k-1]="BLACK";

    int flag=0;

    while (q1.isempty()!=1)
    {
        ll check = q1.Front();
        q1.pop();

        for (ll i = 0; i < n; i++)
        {
            if (atri[i] == "WHITE")
            {
                if (M[check][i] == 1)
                {
                    q1.push(i);
                    if(i==n-1){
                        flag=1;
                    }
                }
            }
        }
        atri[check] = "BLACK";
    }
    if(flag==1){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }


    
    
}
