#include<bits/stdc++.h>
using namespace std;

int cnt=0;

int findParent(int a,vector<int>& parent)
{
    if(a==parent[a]) return a;
    return parent[a]=findParent(parent[a],parent);
}

void dsu(int a,int b,vector<int>& parent,vector<int>& size,int& maxSize)
{
    int par_a=findParent(a,parent);
    int par_b=findParent(b,parent);
    // cout<<par_a<<" "<<par_b<<endl;
    if(par_a==par_b)
    {
        return ;
    }
    else
    {
        cnt++;
        // cout<<par_a<<" "<<par_b<<endl;
        // cout<<size[par_a]<<" "<<size[par_b]<<endl;
        // if(size[par_a]>size[par_b])
        // {
        //     swap(par_a,par_b);
        // }
        parent[par_b]=par_a;
        size[par_a]+=size[par_b];
        // cout<<size[par_b]<<" "<<size[par_a]<<endl;
        maxSize=max(maxSize,max(size[par_a],size[par_b]));
    }
}

int main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    vector<int> size(n+1,1);
    int maxSize=1;
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        dsu(a,b,parent,size,maxSize);
        cout<<n-cnt<<" "<<maxSize<<endl;
    }
    return 0;
}