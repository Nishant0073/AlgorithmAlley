#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(int i,int n,int k,vector<vector<int>> &ans,vector<int> v)
    {
        if(k==0)
        {
            ans.push_back(v);
            return;
        }

        if(i>n)
        return;

        for(int j=i;j<=n;j++)
        {
            if(k-1>=0)
            {
                v.push_back(j);
                solve(j+1,n,k-1,ans,v);
                v.pop_back();
            }
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1,n,k,ans,v);
        return ans;
    }
};

/*
Time Complexity: O(k*n);
Space Complexity: O(k) (Stack);

*/