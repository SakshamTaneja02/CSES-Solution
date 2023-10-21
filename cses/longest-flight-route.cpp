#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back({b,-1});
    }
    vector<int> dist(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1]=0;
    int vertex=0;
    vector<int> parent(n+1,-1);
    while(!pq.empty())
    {
        int w=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto i:graph[node])
        {
            int x=i.first;
            int y=i.second;
            if(dist[x]>dist[node]+y)
            {
                dist[x]=dist[node]+y;
                pq.push({dist[node]+y,x});
                parent[x]=node;
            }
        }
    }
    if(dist[n]==0)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    int temp=n;
    while(temp!=-1)
    {
        ans.push_back(temp);
        temp=parent[temp];
    }
    cout<<ans.size()<<endl;
    for(int i=(int)ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
}