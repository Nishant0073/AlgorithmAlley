class UnionFind
{
    private:
    vector<int> v;

    public:
    UnionFind(int n)
    {
        for(int i=0;i<n;i++)
            v.push_back(i);
    }

    void unionf(int x,int y)
    {
        int xx = find(x);
        int yy = find(y);

        if(xx!=yy)
            v[xx] = yy;
    }

    int  find(int x)
    {
        int tmp = x;
        while(tmp!=v[tmp])
            tmp = v[tmp]
        
        //path compression
        while(x!=tmp)
        {
            int next = v[x];
            v[x] = tmp;
            x = next;
        }

        return x;
    }
    
};

class Solution {
public:
    /*
    0 1 2
    0 1 2

    0 1 2
    0 0 0
    
    */

    bool validPath(int n, vector<vector<int>>& edges, int source, int dest)
    {

        UnionFind* u = new UnionFind(n);

         for(int i=0;i<edges.size();i++)
             u->unionf(edges[i][0],edges[i][1]);

        int x = u->find(source);
        int y = u->find(dest);
        
        cout<<x<<" "<<y<<endl;
        return x==y;
    }       
};