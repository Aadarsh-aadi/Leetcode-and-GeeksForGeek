// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> graph[]) 
	{
	    // code here
	    //kahn's algo
	    vector<int> inDegree(v,0);
	    int i,j;
	    
	    //initialize inDegree vector 
	    
	    for(i=0;i<v;++i)
	    {
	        for(auto u : graph[i])
	        {
	            inDegree[u]++;
	        }
	    }
	    
	    //initialize queue for traveral in topological sorted way
	    queue<int> q;
	    
	    
	    for(i=0;i<v;++i)
	    {
	        if(inDegree[i] == 0)
	            q.push(i);
	    }
	    
	    // initialize answer vector
	    vector<int> ans;
	    
	    
	    // kahn's algorithm
	    while(!q.empty())
	    {
	        i = q.front();
	        q.pop();
	        ans.push_back(i);
	        
	        for(auto u : graph[i])
	        {
	            inDegree[u]--;
	            if(inDegree[u] == 0)
	            {
	                q.push(u);
	            }
	        }
	        
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends