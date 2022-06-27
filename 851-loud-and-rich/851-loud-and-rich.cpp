class Solution {
public:
    // returns index 
    int dfs(vector<vector<int>>& graph , vector<int>& memo , vector<int>& quiet , int index)
    {
        if(memo[index] != -1)
            return memo[index];
        
        int mn = index;
        
        for(auto child : graph[index])
        {
            int temp = dfs(graph,memo,quiet,child);
            if(quiet[mn] > quiet[temp])
                mn = temp;
        }
        
        return memo[index] = mn;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        int r = richer.size() , n = quiet.size(),i;
        
        vector<vector<int>> graph(n);
        vector<int> memo(n,-1),ans(n);
        
        for(i=0;i<r;++i)
        {
            graph[richer[i][1]].push_back(richer[i][0]);;
        }
        
        for(i=0;i<n;++i)
        {
            ans[i] = dfs(graph,memo,quiet,i);
        }
        
        return ans;
    }
};