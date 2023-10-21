#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<vector<int>> dist(n+1,vector<int>(k,LLONG_MAX));
    dist[1][0]=0;
    while(!pq.empty())
    {
        int weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dist[node][k-1]<weight) continue;
        for(int i=0;i<graph[node].size();i++)
        {
            int x=graph[node][i].first;
            int y=graph[node][i].second;
            if(dist[x][k-1]>weight+y)
            {
                dist[x][k-1]=weight+y;
                pq.push({weight+y,x});
                sort(dist[x].begin(),dist[x].end());
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<dist[n][i]<<" ";
    }
}