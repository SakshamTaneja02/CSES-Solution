#include<bits/stdc++.h>
using namespace std;

int dp[21][1<<21];
int mod=1e9+7;

int helper(int src,int mask,int& dest,vector<vector<int> >& graph)
{
    if(src==dest)
    {
        if(mask==pow(2,dest+1)-2) return 1;
        return 0;
    }
    if(dp[src][mask]!=-1) return dp[src][mask];
    int ans=0;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        if((mask&(1<<x))==0)
        {
            ans=(ans%mod+helper(x,mask|(1<<x),dest,graph)%mod)%mod;
        }
    }
    return dp[src][mask]=ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    cout<<helper(1,1<<1,n,graph);
}