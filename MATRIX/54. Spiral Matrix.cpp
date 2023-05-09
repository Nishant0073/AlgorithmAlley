/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

r = 4-1, c = 4-1  , int ti = 0, tj=0;
00 01 02 03 1st i = ti, j= tj   j<=c
12 23 33    2nd i++,j--  i<=r
32 31 30    3rd j--,i-- j>=tj,
20 10       4th j++,i-- i>ti
11 12           ti++,tj++,c--,r--
22 21

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int size = r*c;

        int i=0,j=0,ti=0,tj=0;
        c--,r--;
        vector<int> ans;
        while(ti<=r && tj<=c)
        {
          i=ti,j=tj;

          while(ans.size()!=size && j<=c)
          {
              ans.push_back(matrix[i][j++]);
          }
          i++,j--;
          
          while(ans.size()!=size && i<=r)
          {
              ans.push_back(matrix[i++][j]);
          }
          i--,j--;
          while(ans.size()!=size && j>=tj)
          {
              ans.push_back(matrix[i][j--]);
          }  
          j++,i--;
          while(ans.size()!=size && i>ti)
          {
              ans.push_back(matrix[i--][j]);
          }
          ti++,tj++,r--,c--;
        }

        return ans;

    }
};