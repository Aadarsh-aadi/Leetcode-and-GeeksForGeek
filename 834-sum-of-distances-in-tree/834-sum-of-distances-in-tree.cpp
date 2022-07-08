class Solution {
public:
    vector<int> ans , count;
    vector<vector<int>> graph;
    void dfs1(int node , int parent)
    {
        for(auto neighbor : graph[node])
        {
            if(neighbor != parent)
            {
                dfs1(neighbor,node);
                ans[node] += ans[neighbor] + count[neighbor];
                count[node] += count[neighbor];
            }
        }
    }
    void dfs2(int node , int parent , int n)
    {
        for(auto neighbor : graph[node])
        {
            if(neighbor != parent)
            {
                 ans[neighbor] = ans[node] - count[neighbor] + n - count[neighbor];
                 dfs2(neighbor,node,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        graph = vector<vector<int>>(n);
        ans = vector<int>(n,0);
        count = vector<int>(n,1);
        
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs1(0,-1);
        dfs2(0,-1,n);
        
        return ans;
        
    }
};