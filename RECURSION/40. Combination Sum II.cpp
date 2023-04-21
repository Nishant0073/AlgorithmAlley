#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> v;
    void solve(vector<int> cand,vector<int> tmp,int i,int n,int k)
    {
        if(k==0)
        {
            v.push_back(tmp);
            return;
        }

        if(i==n || k<0)
            return;
        for(int j=i;j<n;j++)
        {
            if(j!=i && cand[j]==cand[j-1])
                continue;
            tmp.push_back(cand[j]);
            solve(cand,tmp,j+1,n,k-cand[j]);
            tmp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
       vector<int> tmp;
       solve(candidates,tmp,0,candidates.size(),target);
        return v; 
    }
};