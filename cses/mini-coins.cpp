#include<bits/stdc++.h>
using namespace std;

long long getCount(vector<int>& coins,int x,vector<long long>& dp)
{
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    long long ans=INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
       if(x-coins[i]>=0) ans=min((long long)ans,1+getCount(coins,x-coins[i],dp));
    }
    return dp[x]=ans;
}

int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    vector<long long> dp(x+1,-1);
    long long k=getCount(coins,x,dp);
    if(k>=INT_MAX) cout<<"-1";
    else cout<<k;
    return 0;
}