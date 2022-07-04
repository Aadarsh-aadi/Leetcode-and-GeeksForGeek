class Solution {
public:
    vector<int> vis;
    int dfs(int index , vector<vector<int>>& graph)
    {
        vis[index] = true;
        int res = 0;
        
        for(auto g : graph[index])
        {
            res = max(res,dfs(g,graph));
        }
        
        return res + 1;
    }
    int maximumInvitations(vector<int>& fav) 
    {
        int n = fav.size() , i, j, k;
        vector<vector<int>> graph(n);
        
        vis = vector<int>(n,false);
        
        for(i = 0 ; i < n ;++i)
        {
            if(fav[fav[i]] != i)
                graph[fav[i]].push_back(i);
        }
        
        int res = 0;
        
         
        for(i = 0 ; i < n ;++i)
        {
            if(fav[fav[i]] == i)
                res += dfs(i,graph);
        }
        
        // count cyclic nodes
        
        for(i = 0 ; i < n ; ++i)
        {
            int cnt = 0;
            
            for(j = i ; vis[j] == false ; j = fav[j])
            {
                vis[j] = true;
                cnt++;
            }
            
            for(k = i ; k != j ; k = fav[k])
            {
                cnt--;
            }
            
            res = max(res,cnt);
        }
        
        return res;
    }
};

/*
0 1 2 3 4 5
1 0 3 4 5 3

*/