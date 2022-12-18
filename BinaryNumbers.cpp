#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
class queue
{
public:
    string arr[INT8_MAX];
    int top = 0;
    int rear = 0;
    int size = rear - top;

    void push(string num)
    {
        size = rear - top;
        /*if(rear==2147483647){
            rear=0;
        }*/
        if (size == 0)
        {
            arr[top] = num;
            rear++;
            // cout<<"Arr top is:"<<arr[top]<<endl;
        }
        else
        {
            arr[rear] = num;
            rear++;
        }
        size = rear - top;
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
    string front()
    {
        size = rear - top;
        if (size == 0)
        {
            return ("-1");
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

string Binary(int n)
{
    string s = "1";
    queue q1;
    q1.push(s);

    
    while (q1.isempty() != 1)
    {
        // cout<<"Check1"<<endl;
        s = q1.front();
        int val = stoi(s);
 
        q1.pop();
        if (val % n == 0)
        {
            // cout<<"The given val is"<<val<<endl;
            return (s);
        }
        else
        {
            q1.push(s + "0");
            q1.push(s + "1");
        }
    }
    return "1";
}

int main()
{
    int n;
    cin >> n;
    cout << Binary(n) << endl;
}
