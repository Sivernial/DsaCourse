#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] <<' ' ;
    cout << endl;
}
int main()
{
        string s;
        cin>>s;
        int n=s.size();
        string sub_s="";
        int index=3;
        int val=int(s[0]);
        while (index!=n)
        {
            while (s[index]!=']')
            {
                sub_s+=s[index];
                index++;
            }
            for (int i = 0; i < val; i++)
            {
                cout<<sub_s;
            }
            sub_s="";
            index+=2;
            val=int(s[0]);          

        }
        
        
        

}