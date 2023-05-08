/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33
r c
0 0
0 3
1 1
1 2
2 1
2 2
3 0 
3 3

*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size()-1;
        int m = mat[0].size()-1;
        int r = 0,c =0;
        int sum = 0;

        while(r<=n && c<=m)
        {
            sum+=mat[r][c];
            if(c!=(m-c))
                sum+=mat[r][m-c];
            c++,r++;
        }

        return sum;
    }
};
