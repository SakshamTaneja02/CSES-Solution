#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int getCount(vector<vector<char> >& grid,int row,int col,vector<vector<int> >& dp)
{
    if(row>=grid.size() || row<0) return 0;
    if(col>=grid.size() || col<0) return 0;
    if(grid[row][col]=='*') return 0;
    if(row==grid.size()-1 && col==grid.size()-1)
    {
        return 1;
    }
    if(dp[row][col]!=-1) return dp[row][col];
    int op1=getCount(grid,row+1,col,dp);
    int op2=getCount(grid,row,col+1,dp);
    return dp[row][col]=(op1%mod+op2%mod)%mod;
}

int main()
{
    int n;
    cin>>n; 
    vector<vector<char> > grid(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int> > dp(n,vector<int>(n,-1));
    cout<<getCount(grid,0,0,dp);
}