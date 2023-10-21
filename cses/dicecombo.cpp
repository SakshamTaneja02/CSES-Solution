#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

long long getCount(int n,vector<int>& dp)
{
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    long long ans=0;
    for(int i=1;i<=6;i++)
    {
        if(n-i>=0) ans=(ans%mod+getCount(n-i,dp)%mod)%mod;
    }
    return dp[n]=ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<getCount(n,dp)<<endl;
}