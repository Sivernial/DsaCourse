#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
template<class T>
class queue
{
public:
    T arr[INT16_MAX];
    int top = 0;
    int rear = 0;
    int size = rear - top;

        void push(T val){
            if(size<=INT16_MAX){
                rear++;
            }
            if(rear>=INT16_MAX){
                rear = 0;
            }
            arr[rear] = val;
            rear++;
            return;
        }

    void pop()
    {
        size = rear - top;
        if (size == 0)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            // cout<<arr[top]<<endl;
            arr[top] = {};
            top++;
        }
    }
    int front()
    {
        size = rear - top;
        if (size == 0)
        {
            return (-1);
        }
        else
        {
            return (arr[top]);
        }
    }
    void back()
    {
        size = rear - top;
        if (size == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << arr[rear - 1] << endl;
        }
    }
    void sizes()
    {
        cout << (rear - top) << endl;
    }

    int isempty()
    {
        if (size == 0)
        {
            return (1);
        }
        else
        {
            return (0);
        }
    }
};

bool isInside(int x, int y, int N,int M)
{
	if (x >= 1 && x <= N && y >= 1 && y <= M)
		return true;
	return false;
}

int Moves(int A, int B, int C,int D, int E, int F)
						
{
    int a,b;
	// x and y direction, where a knight can move
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	// queue for storing states of knight in board
	bool visited[A+1][B+1]={false};
    visited[C][D]=true;
    int x,y,m=0;
    queue<int> q_x;
    q_x.push(C);
    queue<int> q_y;
    q_y.push(D);
    queue<int> q_m;
    q_m.push(0);
    while (!q_x.isempty()&& !q_y.isempty())
    {
        x=q_x.front();
        y=q_y.front();
        m=q_m.front();
        q_x.pop();
        q_y.pop();
        q_m.pop();
        if (x==E && y==F)
        {
            return m;
        }
        for (int i = 0; i < 8; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            if (isInside(a,b,A,B)&&  !visited[a][b])
            {
                visited[a][b]=true;
                q_x.push(a);
                q_y.push(b);
                q_m.push(m+1);
                
            }
            
        }
        
    }
    return -1;
    

	
}


int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<Moves(a,b,c,d,e,f);
	return 0;
}
