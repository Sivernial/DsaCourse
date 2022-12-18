#include <iostream>
typedef long long int ll;
using namespace std;
template <class T>

class Queue
{
    T *arr;
    ll back = -1;
    ll front = 0;
    ll currsize = 0;

public:
    Queue()
    {
        arr = new T[INT16_MAX];
    }
    bool isempty()
    {
        if (currsize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(T val)
    {
        if (currsize <= INT16_MAX)
        {
            back++;
        }
        if (back >= INT16_MAX)
        {
            back = 0;
        }
        arr[back] = val;
        currsize++;
        return;
    }
    void pop()
    {
        if (!isempty())
        {
            currsize--;
            front++;
            return;
        }
        return;
    }
    T Front()
    {
        return arr[front];
    }
};
int flag=0;
Queue<int> qx;
Queue<int> qy;

void SurroundCheck(int **M, int x, int y, int n, int m,int a,int b)
{
    while (qx.isempty()==false)
    {
        x=qx.Front();
        y=qy.Front();
        qx.pop();
        qy.pop();
        if (x < 0 || y < 0 || x > (n - 1) || y > (m - 1) || M[x][y] != 1)
    {
        return;
    }
    if (M[x][y] == 1)
    {
        if (x == a && y == b)
        {
            flag=1;
            return;
        }
        else
        {
            M[x][y] = 0;
            qx.push(x+1);
            qy.push(y+1);

            qx.push(x+1);
            qy.push(y-1);
            
            qx.push(x-1);
            qy.push(y-1);

            qx.push(x-1);
            qy.push(y+1);
            
            qx.push(x);
            qy.push(y-1);
            
            qx.push(x);
            qy.push(y+1);
            
            qx.push(x+1);
            qy.push(y);
            
            qx.push(x-1);
            qy.push(y);
        }
    }
    }
    flag=-1;
    return;
    
    
}
int main()
{
    int n, m;
    cin >> n >> m;
    int **Matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        Matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            Matrix[i][j] = val;
        }
    }
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < m; i++)
    {
        if (Matrix[0][i]==1 && flag!=1)
        {
            SurroundCheck(Matrix,0,i,n,m,x,y);
        }        
    }
    for (int i = 0; i < n; i++)
    {
        if (Matrix[i][0]==1 && flag!=1)
        {
            SurroundCheck(Matrix,i,0,n,m,x,y);
        }        
    }
    for (int i = 0; i < m; i++)
    {
        if (Matrix[n-1][i]==1 && flag!=1)
        {
            SurroundCheck(Matrix,n-1,i,n,m,x,y);
        }        
    }
    for (int i = 0; i < n; i++)
    {
        if (Matrix[i][m-1]==1 && flag!=1)
        {
            SurroundCheck(Matrix,i,m-1,n,m,x,y);
        }        
    }
    if (flag==-1)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    

    
    
}