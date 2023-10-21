#include<bits/stdc++.h>
using namespace std;

int getCount(vector<int>& dp,int n)
{
    if(n==0) return 0;
    if(n<0) return 1e7;
    if(dp[n]!=-1) return dp[n];
    int a=n;
    int ans=INT_MAX;
    while(a>0)
    {
        // cout<<a<<endl;
        int digit=a%10;
        if(n-digit>=0 && digit!=0) ans=min(ans,1+getCount(dp,n-digit));
        a=a/10;
    }
    return dp[n]=ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<getCount(dp,n);
    return 0;
}