// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool checkForCycle(vector<int> adj[], int s, vector<bool>& visited, vector<bool>& dfsVisited){
	    visited[s] = true;
	    dfsVisited[s] = true;
	    for(auto e : adj[s]){
	        if(!visited[e]){
	            if(checkForCycle(adj, e, visited, dfsVisited))
	                return true;
	        }
	        else if(dfsVisited[e])
	            return true;
	    }
	    dfsVisited[s] = false;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> visited(V, 0), dfsVisited(V, 0);
	   	for(int i = 0; i < V; i++){
	   	    if(checkForCycle(adj, i, visited, dfsVisited))
	   	        return true;
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
