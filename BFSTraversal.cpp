#include <iostream>
// #include <queue>
//#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int arr[INT8_MAX];
    int top = 0;
    int rear = 0;
    int size = rear - top;

    void push(int num)
    {
        size = rear - top;
        /*if(rear==2147483647){
            rear=0;
        }*/
        // if (size == 0)
        // {
        //     arr[top] = num;
        //     rear++;
        //     // cout<<"Arr top is:"<<arr[top]<<endl;
        // }
        // else
        // {
            arr[rear] = num;
            rear++;
        // }
    }

    int pop()
    {
        size = rear - top;
        if (size == 0)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            top++;
            return (arr[top-1]);
                    
        }
    }
    void front()
    {
        size = rear - top;
        if (size == 0)
        {
            cout << (-1) << endl;
        }
        else
        {
            cout << (arr[top]) << endl;
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
        if (rear-top == 0)
        {
            return(1) ;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    int colour[n];
    for (int i = 0; i < n; i++)
    {
        colour[i] = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ele=0;
    Queue q1;
    colour[0]=1;
    cout<<0<<" ";
    q1.push(ele);
    while (q1.isempty()!=1)
    {
        int row=q1.pop();
        // cout<<row<<" ";
        for (int i = 0; i < n; i++)
        {
            if(colour[i]==0 && arr[row][i]==1){
                colour[i]=1;
                cout<<i<<" ";
                q1.push(i);
            }
        }
        
    }
    
}