class Solution {
public:
    vector<int> longest;
    vector<vector<int>> adj;
    
    int dfs(int src){
        if(longest[src] != -1) return longest[src];
        int res = 0;
        for(int neigh: adj[src])
            res = max(res, dfs(neigh));
        return longest[src] = res + 1;
    }
    
    //check if s1 is predecessor of s2
    bool is_pred(string& s1, string& s2){
        if(s1.length() + 1 != s2.length()) return false;
        bool inserted = false;
        int i = 0, j = 0;
        while(i < s1.length()){
            if(s1[i] != s2[j]){
                if(inserted) return false;
                inserted = true;
                ++j;
            }else{
                ++i;
                ++j;
            }
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        adj.assign(n, vector<int>());
        longest.assign(n, -1);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                if(is_pred(words[i], words[j]))
                    adj[i].push_back(j);
            }
        }
        
        int res = 0;
        
        for(int i = 0; i < n; ++i)
            if(longest[i] == -1)
                res = max(res, dfs(i));
        
        return res;
    }
};