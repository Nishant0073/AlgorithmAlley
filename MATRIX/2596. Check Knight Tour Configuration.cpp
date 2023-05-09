/*

1.we need to find all moves can be made if knife at position i,j

{
     -1,+2,
     +1,+2,
     -2,+1,
     -2,-1,
     -1,-2,
     +1,-2,
     +2,-1,
     +2,+1
}

store currVal 
check in all possible move if currVal+1 present
if Yes
    mark curr pos as visited i.e -1,
    go to next position
else
    return false;

*/

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> que;
        if(grid[0][0]!=0)
                return false;
        que.push({{0,0},0});

        int x[] = {-1,+1,-2,-2,-1,+1,+2,+2};
        int y[] = {+2,+2,+1,-1,-2,-2,-1,+1};
        while(que.size()!=0)
        {
            int i = que.front().first.first;
            int j = que.front().first.second;
            int move = que.front().second;
            grid[i][j] = -1;
            que.pop();
            for(int k=0;k<8;k++)
            {
                int ki = i+x[k];
                int kj = j+y[k];
                if(ki>=0 && kj>=0 && ki<n && kj<m && grid[ki][kj]==move+1)
                {

                    que.push({{ki,kj},move+1});
                    break;
                }
                return false;
            }
        }

        return true;
    }
};