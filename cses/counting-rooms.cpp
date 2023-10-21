#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char> >& grid,vector<vector<bool> >& visit,int row,int col)
{
    if(row>=grid.size() || row<0) return ;
    if(col>=grid[0].size() || col<0) return ;
    if(visit[row][col]==true) return ;
    if(grid[row][col]=='#') return ;
    visit[row][col]=true;
    dfs(grid,visit,row+1,col);
    dfs(grid,visit,row-1,col);
    dfs(grid,visit,row,col+1);
    dfs(grid,visit,row,col-1);
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<char> > grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int cnt=0;
    vector<vector<bool> > visit(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visit[i][j]==false && grid[i][j]=='.')
            {
                dfs(grid,visit,i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
}