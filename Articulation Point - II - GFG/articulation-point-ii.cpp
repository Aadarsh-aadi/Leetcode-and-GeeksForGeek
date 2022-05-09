// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void AP(int V, vector<int>adj[] , bool visited[] , int disc[] , int low[] ,
            vector<int> &isAP, int parent , int &disc_time , int u  )
    {
        visited[u] = true ;
        disc_time ++ ;
        disc[u] = low[u] = disc_time ;
        int children = 0;
        
        for(int v : adj[u])
        {
            if(!visited[v])
            {
                AP(V,adj,visited,disc,low,isAP,u,disc_time,v);
                children++;
                
                low[u] = min(low[u], low[v]);
                
                if(parent != -1 && low[v] >= disc[u])
                {
                    isAP[u] = 1;
                }
                    
            }
            else if(parent != v)
            {
                low[u] = min(low[u] , disc[v]);
            }
                
                
        }
        if(parent== -1 && children>1)
            isAP[u] = 1;
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        bool visited[V] = {false};
        int disc[V] = {0};
        int low[V] = {0};
        vector<int> isAP(V,0);
        
        int parent = -1 , disc_time = 0 ;
        
        for(int i=0 ; i<V ; i++)
        {
            if(!visited[i])
            {
                AP(V,adj,visited,disc,low,isAP,-1,disc_time,i);
            }
        }
        vector<int> res;
        for(int i=0;i<V;i++)
        {
            if(isAP[i] == 1)
                res.push_back(i);
                
        }
        if (res.size() == 0)
            res.push_back(-1);
            
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends