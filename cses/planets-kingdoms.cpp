#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<bool>& visit,stack<int>& s,vector<vector<int> >& graph)
{
    visit[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        if(visit[x]==false)
        {
            dfs(x,visit,s,graph);
        }
    }
    s.push(src);
}

void cc(int src,vector<bool>& visit,vector<vector<int> >& graph,vector<int>& ans,int mark)
{
    ans[src]=mark;
    visit[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        if(visit[x]==false)
        {
            cc(x,visit,graph,ans,mark);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    vector<vector<int> > graphRev(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graphRev[b].push_back(a);
    }
    vector<bool> visit(n+1,false);
    stack<int> s;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            dfs(i,visit,s,graph);
        }
    }
    vector<bool> visit2(n+1,false);
    vector<int> ans(n+1,-1);
    int cnt=1;
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(visit2[node]==false)
        {
            cc(node,visit2,graphRev,ans,cnt);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}