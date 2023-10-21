t#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>& a,vector<int>& b)
{
    return a[1]<b[1];
}

int find(vector<vector<int> >& vec,int idx)
{
    int start=0,end=idx-1;
    while(start <= end)//Binary Search
    {
        int mid = (start+end)/2;
        if(vec[mid][1] < vec[idx][0])
        {
            if(vec[mid+1][1] < vec[idx][0])
            start = mid + 1;
 
            else
            return mid;
        }
 
        else
        end = mid - 1;
 
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > vec;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> temp;
        temp.push_back(a); temp.push_back(b); temp.push_back(c);
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end(),comp);
    vector<long long> dp(n+1);
    dp[0]=vec[0][2];
    for(int i=1;i<vec.size();i++)
    {
        long long temp = vec[i][2];
        int search = find(vec,i); 
        if(search != -1)
            temp += dp[search];
        dp[i] = max(dp[i-1],temp); 
    }
    cout<<dp[n-1];
}