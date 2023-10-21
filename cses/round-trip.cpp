#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,int par,vector<bool>& visit,vector<int>& parent,vector<vector<int> >& graph,int& sv,int &ev)
{
    visit[src]=true;
    parent[src]=par;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        if(visit[x]==false)
        {
            if(dfs(x,src,visit,parent,graph,sv,ev)==true) return true;
        }
        else if(x!=par)
        {
            sv=x;
            ev=src;
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visit(n+1,false);
    vector<int> parent(n+1,-1);
    bool flag=false;
    int sv=0,ev=0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            if(dfs(i,-1,visit,parent,graph,sv,ev)==true)
            {
                flag=true;
                break;
            }
        }
    }
    if(flag==false)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path;
    int tv=ev;
    path.push_back(ev);
    while(ev!=sv)
    {
        path.push_back(parent[ev]);
        ev=parent[ev];
    }
    path.push_back(tv);
    cout<<path.size()<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
}