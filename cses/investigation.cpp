#include<bits/stdc++.h>
using namespace std;
#define int long long int

int mod=1e9+7;

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    vector<int> cost(n+1,LLONG_MAX);
    cost[1]=0;
    vector<int> max_f(n+1,0);
    vector<int> min_f(n+1,LLONG_MAX);
    vector<int> route(n+1,LLONG_MIN);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    route[1]=1;
    cost[1]=0;
    min_f[1]=0;
    max_f[1]=0;
    while(!pq.empty())
    {
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d>cost[u]) continue;
        for(auto e:graph[u])
        {
            int v=e.first;
            int c=e.second;
            if(c+d==cost[v])
            {
                route[v]+=route[u];
                route[v]%=mod;
                min_f[v]=min(min_f[v],1+min_f[u]);
                max_f[v]=max(max_f[v],max_f[u]+1);
            }
            if(c+d<cost[v])
            {
                cost[v]=c+d;
                route[v]=route[u];
                min_f[v]=1+min_f[u];
                max_f[v]=1+max_f[u];
                pq.push({cost[v],v});
            }
        }
    }
    cout<<cost[n]<<" "<<route[n]<<" "<<min_f[n]<<" "<<max_f[n]<<endl;
}