#include<bits/stdc++.h>
using namespace std;

long long getMaxScore(vector<int>& vec,int start,int end,vector<vector<long long> >& dp)
{
    if(start>end) return 0;
    if(start==end) return vec[start];
    if(dp[start][end]!=-1) return dp[start][end];
    long long op1=vec[start]+min(getMaxScore(vec,start+1,end-1,dp),getMaxScore(vec,start+2,end,dp));
    long long op2=vec[end]+min(getMaxScore(vec,start+1,end-1,dp),getMaxScore(vec,start,end-2,dp));
    return dp[start][end]=max(op1,op2);
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    vector<vector<long long> > dp(n+1,vector<long long>(n+1,-1));
    cout<<getMaxScore(vec,0,vec.size()-1,dp);
}