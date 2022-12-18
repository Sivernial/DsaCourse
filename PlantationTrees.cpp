#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int total=n*m;
    int exclusion=n+m;
    cout<<2*total-(exclusion)<<endl;
}