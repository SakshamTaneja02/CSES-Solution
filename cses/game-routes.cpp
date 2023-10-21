#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int dfs(int src,int dest,vector<vector<int> >& graph,vector<int>& dp)
{
    if(src==dest) return 1;
    if(dp[src]!=-1) return dp[src];
    int ans=0;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        ans=(ans%mod+dfs(x,dest,graph,dp)%mod)%mod;
    }
    return dp[src]=ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<int> dp(n+1,-1);
    cout<<dfs(1,n,graph,dp);
}