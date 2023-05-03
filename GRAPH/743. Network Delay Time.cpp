
//https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<pair<int,int>> adj[n+1];

            for(int i=0;i<times.size();i++)
                adj[times[i][0]].push_back({times[i][1],times[i][2]});
            
            vector<int> v(n+1,INT_MAX);

            queue<pair<int,int>> que;
            v[k] = 0;
            que.push({k,0});

            while(!que.empty())
            {
                int node = que.front().first;
                int dist = que.front().second;

                que.pop();
                for(auto it:adj[node])
                {
                    int cnode = it.first;
                    int cdist = it.second;
                    int tdist = cdist+dist;
                    if(tdist<v[cnode])
                    {
                        v[cnode] = tdist;
                        que.push({cnode, tdist});
                    }
                }
            }

            int minPath = INT_MIN;
            for(int i=1;i<=n;i++)
            {
                if(v[i]==INT_MAX)
                    return -1;
                minPath = max(minPath,v[i]);
            }

            return minPath;
    }
};

