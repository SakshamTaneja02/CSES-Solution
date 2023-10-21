#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int main()
{
    int n;
    cin>>n;
    int sum=(n*(n+1))/2;
    vector<vector<long long> > dp(n+1,vector<long long>(sum+1,0));
    if(sum%2==1)
    {
        cout<<0;
        return 0;
    }
    sum=sum/2;
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-i>=0)
            {
                (dp[i][j]+=dp[i-1][j-i])%=mod;
            }
        }
    }
    cout<<dp[n-1][sum];
}