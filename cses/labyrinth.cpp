#include<bits/stdc++.h>
using namespace std;

class quad
{
    public:
    int row,col,size;
    string s;
    quad(int r,int c,int si,string t)
    {
        row=r; col=c; size=si;
        s=t;
    }
};

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<char> > grid(n,vector<char>(m));
    int srow=0,scol=0,erow=0,ecol=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')
            {
                srow=i;
                scol=j;
            }
            else if(grid[i][j]=='B')
            {
                erow=i;
                ecol=j;
            }
        }
    }
    vector<vector<bool> > visit(n+1,vector<bool>(m+1,false));
    queue<quad> q;
    q.push({srow,scol,0,""});
    visit[srow][scol]=true;
    vector<int> dx={0,0,-1,1};
    vector<int> dy={1,-1,0,0};
    vector<char> d={'R','L','U','D'};
    quad ans={-1,-1,-1,""};
    while(!q.empty())
    {
        quad t=q.front();
        q.pop();
        if(t.row==erow && t.col==ecol)
        {
            // cout<<t.row<<" "<<t.col<<" "<<t.size<<" "<<t.s<<endl;
            ans=t;
            break;
        }
        for(int i=0;i<4;i++)
        {
            int row=t.row+dx[i];
            int col=t.col+dy[i];
            string path=t.s+d[i];
            if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]!='#' && visit[row][col]==false)
            {
                q.push({row,col,t.size+1,path});
                visit[row][col]=true;
            }
        }
    }
    if(ans.row==-1)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<ans.size<<endl;
        cout<<ans.s;
    }
    return 0;
}