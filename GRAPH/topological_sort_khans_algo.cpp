class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> tps;
	    queue<int> qe;
	    vector<int> inDeg(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	            inDeg[it]++;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(inDeg[i]==0)
	            qe.push(i);
	        
	    }
	    while(!qe.empty())
	   {
	       int curr = qe.front();
	       tps.push_back(curr);
	       qe.pop();
	       for(auto it:adj[curr])
	       {
	           if(--inDeg[it]==0)
	            qe.push(it);
	       }
	   }
	   return tps;
	}
};