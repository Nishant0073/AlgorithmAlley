// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++)
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        
         vector<int> v(n,INT_MAX);
         queue<pair<int,pair<int,int>>> que;


         que.push({src,{0,0}});
         while(que.empty()==false)
         {
             int node = que.front().first;
             int cost = que.front().second.first;
             int stop = que.front().second.second;
             que.pop();
             
             for(auto it:adj[node])
             {
                 int cnode = it.first;
                 int ccost = it.second;
                 int tcost = ccost+cost;
                 if(v[cnode]>(tcost) && stop<=k)
                 {
                     v[cnode] = tcost;
                     que.push({cnode,{tcost,stop+1}});
                 }
             }
         }

         if(v[dst]==INT_MAX)
            return -1;

        return v[dst];

    }
};