#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int q;
    cin>>q;
    vector<vector<long long> > graph(n+1,vector<long long>(n+1,1e14));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b],(long long)c);
        graph[b][a]=min(graph[b][a],(long long)c);
    }
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph.size();j++)
        {
            if(i==j) graph[i][j]=0;
        }
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=n;k++)
            {
                if(graph[i][j]!=1e14 || graph[j][k]!=1e14)
                {
                    graph[i][k]=min(graph[i][k],graph[i][j]+graph[j][k]);
                }
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        int a,b; cin>>a>>b;
        if(graph[a][b]>=1e14) cout<<"-1"<<endl;
        else cout<<graph[a][b]<<endl;
    }
    return 0;
}