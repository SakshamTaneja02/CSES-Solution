#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<bool>& visit,vector<vector<int> >& graph)
{
    visit[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        int x=graph[src][i];
        if(visit[x]==false)
        {
            dfs(x,visit,graph);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > g1(n+1);
    vector<vector<int> > g2(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    vector<bool> visit(n+1,false);
    dfs(1,visit,g1);
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    vector<bool> visit2(n+1,false);
    dfs(1,visit2,g2);
    for(int i=1;i<=n;i++)
    {
        if(visit2[i]==false)
        {
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}