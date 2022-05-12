class Solution {
public:
    vector<vector<int>> ans;
    map<int,int> mp;
    
    void dfs(vector<int> temp,int n)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto m : mp)
        {
            if(m.second != 0)
            {
                //do
                mp[m.first]--;
                temp.push_back(m.first);
                
                //recur
                dfs(temp,n);
                
                //undo
                temp.pop_back();
                mp[m.first]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        for(auto x : nums)
        {
            mp[x]++;
        }
        
        vector<int> temp;
        dfs(temp,nums.size());
        
        return ans;
    }
};