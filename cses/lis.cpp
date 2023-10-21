#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    vector<int> ans;
    ans.push_back(vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]>ans[ans.size()-1])
        {
            ans.push_back(vec[i]);
        }
        else
        {
            int low=lower_bound(ans.begin(),ans.end(),vec[i])-ans.begin();
            ans[low]=vec[i];
        }
    }
    cout<<ans.size();
}