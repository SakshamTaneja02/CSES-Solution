#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    vector<vector<int> > dp(s.size()+1,vector<int>(t.size()+1,0));
    for(int i=0;i<=s.size();i++) dp[i][0]=i;
    for(int j=0;j<=t.size();j++) dp[0][j]=j;
    for(int i=1;i<=s.size();i++)
    {
        for(int j=1;j<=t.size();j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    cout<<dp[s.size()][t.size()];
}