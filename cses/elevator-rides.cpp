#include<bits/stdc++.h>
using namespace std;
#define lol long long int

int main()
{
    lol n;
    cin>>n;
    lol w;
    cin>>w;
    vector<lol> weights(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    lol limit=1<<n;
    vector<pair<lol,lol>> dp(limit);
    dp[0]={1,0};
    for(lol mask=1;mask<limit;mask++)
    {
        pair<lol,lol> p={INT_MAX,INT_MAX};
        for(lol i=0;i<n;i++)
        {
            if((mask&(1<<i))==0) continue;
            auto res=dp[(1<<i)^mask];
            if(res.second+weights[i]<=w)
            {
                res.second+=weights[i];
            }
            else
            {
                res.first+=1;
                res.second=weights[i];
            }
            p=min(p,res);
        }
        dp[mask]=p;
    }
    cout<<dp[limit-1].first;
}