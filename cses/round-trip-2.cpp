#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,int par,vector<bool>& visit,vector<bool>& helper,vector<int>& parent,vector<vector<int> >& graph,int& sv,int& ev)
{
    helper[src]=true;
    visit[src]=true;
    parent[src]=par;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        if(helper[x]==true)
        {
            sv=x;
            ev=src;
            // cout<<x<<" "<<src<<endl;
            return true;
        }
        if(visit[x]==false)
        {
            if(dfs(x,src,visit,helper,parent,graph,sv,ev)==true) return true;
        }
    }
    helper[src]=false;
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<bool> visit(n+1,false);
    vector<bool> helper(n+1,false);
    vector<int> parent(n+1,-1);
    int sv=0,ev=0;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            if(dfs(i,-1,visit,helper,parent,graph,sv,ev)==true)
            {
                flag=true;
                break;
            }
        }
    }
    if(flag==false)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> cycle;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    int tv=ev;
    cycle.push_back(ev);
    while(ev!=sv)
    {
        cycle.push_back(parent[ev]);
        ev=parent[ev];
    }
    cycle.push_back(tv);
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()<<endl;
    for(int i=0;i<cycle.size();i++)
    {
        cout<<cycle[i]<<" ";
    }
}