#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int> > graph;

void dfs(int src,vector<bool>& visit)
{
    visit[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        if(visit[x]==false)
        {
            dfs(x,visit);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visit(n+1,false);
    vector<int> nodes;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            dfs(i,visit);
            nodes.push_back(i);
        }
    }
    cout<<nodes.size()-1<<endl;
    for(int i=0;i<nodes.size()-1;i++)
    {
        cout<<nodes[i]<<" "<<nodes[i+1]<<endl;
    }
    return 0;
}