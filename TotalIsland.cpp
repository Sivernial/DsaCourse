#include<iostream>
using namespace std;

void SurroundCheck(int** M,int x,int y,int n , int m){
    if(x<0 || y<0 || x>(n-1)||y>(m-1)|| M[x][y]!=1){
        return;
    }
    if (M[x][y]==1)
    {
        M[x][y]=0;
        SurroundCheck(M,x+1,y+1,n,m);
        SurroundCheck(M,x+1,y-1,n,m);
        SurroundCheck(M,x-1,y+1,n,m);
        SurroundCheck(M,x-1,y-1,n,m);
        SurroundCheck(M,x,y+1,n,m);
        SurroundCheck(M,x,y-1,n,m);
        SurroundCheck(M,x+1,y,n,m);
        SurroundCheck(M,x-1,y,n,m);
    }
    
}

int TotalIsland(int n,int m,int** M){
    int total=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j]==1)
            {
                total+=1;
                SurroundCheck(M,i,j,n,m);
                M[i][j]=0;
                
            }
            
        }
        
    }
    return total;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    int** Matrix=new int *[n];
    for (int i = 0; i < n; i++)
    {
        Matrix[i]=new int[m];
        for (int j = 0; j < m; j++)
        {
            int val;
            cin>>val;
            Matrix[i][j]=val;
        }
        
    }
    cout<<TotalIsland(n,m,Matrix);
    
}