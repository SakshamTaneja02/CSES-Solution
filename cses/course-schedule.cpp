#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int> > graph;

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    vector<int> ans;
    queue<int> q;
    for(int i=1;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        if(indegree[top]==0)
        {
            ans.push_back(top);
            // continue;
        }
        for(int i=0;i<graph[top].size();i++)
        {
            int x=graph[top][i];
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }
    if(ans.size()!=n)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}