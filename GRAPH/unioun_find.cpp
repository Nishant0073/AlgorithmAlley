#include<bits/stdc++.h>
using namespace std;


class UnionFind {
    public:
    UnionFind(int n) : parent(n),size(n) {
        iota(parent.begin(), parent.end(), 0);
        for(int i=0;i<n;i++)
                size[i] = 1;
    }

    int Find(int x) {
         if (parent[x] == x) {
                return x;
	 }
            return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        int xx = Find(x);
        int yy = Find(y);
         
        if (xx != yy) {
            if(size[xx]<size[yy])
                swap(xx,yy);
            parent[yy] = xx; 
            size[xx] += size[yy];
         
        }
    }
    
    private:
           vector<int> parent;
           vector<int> size;
};


int main()
{
    std::vector<vector<int>> v = {{0,1},{1,2},{3,4},{5,6},{3,7}};
    UnionFind *u = new UnionFind(8);

    for(int i=0;i<v.size();i++)
        u->Union(v[i][0],v[i][1]);

    u->printGrop(8);
}
