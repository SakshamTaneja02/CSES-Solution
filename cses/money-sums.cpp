#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    int maxsum=(100)*(1000);
    vector<vector<bool> > dp(n+1,vector<bool>(maxsum+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=maxsum;j++)
        {
            dp[i][j]=dp[i-1][j];
            int left=j-vec[i-1];
            if(left>=0 && dp[i-1][left])
            {
                dp[i][j]=true;
            }
        }
    }
    vector<int> possible;
    for(int i=1;i<=maxsum;i++)
    {
        if(dp[n][i])
        {
            possible.push_back(i);
        }
    }
    cout<<possible.size()<<endl;
    for(int i=0;i<possible.size();i++)
    {
        cout<<possible[i]<<" ";
    }
}