#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<pair<int,int> > > graph;

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x; cin>>x; int y; cin>>y; int wt; cin>>wt;
        graph[x].push_back({y,wt});
    }
    vector<long long> dist(n+1,LLONG_MAX);
    dist[1]=0;
    set<pair<long long,long long>> s;
    s.insert({1,dist[1]});
    while(!s.empty())
    {
        pair<long long,long long> top=*s.begin();
        s.erase(s.begin());
        for(pair<long long,long long> p:graph[top.first])
        {
            if(p.second+top.second<dist[p.first])
            {
                auto it=s.find({p.first,dist[p.first]});
                if(it!=s.end())
                {
                    s.erase(it);
                }
                dist[p.first]=p.second+top.second;
                s.insert({p.first,dist[p.first]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}