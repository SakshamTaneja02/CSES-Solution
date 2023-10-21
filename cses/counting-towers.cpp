#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

long long findSum(long long a,long long b)
{
    return (a%mod+b%mod)%mod;
}

int main()
{
    int n=1e6;
    vector<vector<long long> > dp(n+1,vector<long long>(2,0));
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=findSum(2*dp[i-1][0],dp[i-1][1]);
        dp[i][1]=findSum(4*dp[i-1][1],dp[i-1][0]);
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int x; cin>>x;
        cout<<findSum(dp[x][0],dp[x][1])<<endl;
    }
    return 0;
}