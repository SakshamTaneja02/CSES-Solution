#include<bits/stdc++.h>
using namespace std;

bool bfs(int src,vector<int>& color,vector<vector<int> >& graph)
{
    queue<int> q;
    color[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=0;i<graph[top].size();i++)
        {
            int x=graph[top][i];
            if(color[x]==0)
            {
                if(color[top]==1) color[x]=2;
                else color[x]=1;
                q.push(x);
            }
            else if(color[x]==color[top])
            {
                return false;
            }
        }
    }
    return true;
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
        graph[b].push_back(a);
    }
    vector<int> color(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            if(bfs(i,color,graph)==false)
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<" ";
    }
}