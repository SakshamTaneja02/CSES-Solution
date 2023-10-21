#include<bits/stdc++.h>
using namespace std;

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
    vector<int> pred(n+1,-1);
    vector<int> dist(n+1,INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    bool flag=false;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=0;i<graph[top].size();i++)
        {
            int x=graph[top][i];
            if(dist[x]==INT_MAX)
            {
                dist[x]=1+dist[top];
                pred[x]=top;
                q.push(x);
                if(x==n)
                {
                    flag=true;
                    break;
                }
            }
        }
    }
    if(flag==false)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path;
    int curr=n;
    path.push_back(curr);
    while(pred[curr]!=-1)
    {
        path.push_back(pred[curr]);
        curr=pred[curr];
    }
    cout<<path.size()<<endl;
    for(int i=(int)path.size()-1;i>=0;i--)
    {
        cout<<path[i]<<" ";
    }
}