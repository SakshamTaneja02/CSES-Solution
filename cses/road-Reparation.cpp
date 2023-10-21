#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
static bool comp(vector<int>& a,vector<int>& b)
{
    return a[2]<b[2];
}
 
int findParent(int a,vector<int>& parent)
{
    if(a==parent[a]) return a;
    return parent[a]=findParent(parent[a],parent);
}
 
bool dsu(int a,int b,vector<int>& parent,vector<int>& size)
{
    int par_a=findParent(a,parent);
    int par_b=findParent(b,parent);
    if(par_a==par_b) return false;
    parent[par_a]=par_b;
    size[par_a]+=size[par_b];
    return true;
}
 
int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(),edges.end(),comp);
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    vector<int> size(n+1,1);
    int ans=0;
    for(int i=0;i<edges.size();i++)
    {
        if(dsu(edges[i][0],edges[i][1],parent,size))
        {
            n--;
            ans+=edges[i][2];
        }
    }
    if(n==1) cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}