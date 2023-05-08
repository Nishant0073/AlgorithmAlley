class UnionFind {
    public:
    UnionFind(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
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
            parent[xx] = yy;
        }
    }

    private:
           vector<int> parent;
};
