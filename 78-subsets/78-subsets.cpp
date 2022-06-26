class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> nums, int start , int end , vector<int>& curr)
    {
        for(int i=start;i<end;++i)
        {
            curr.push_back(nums[i]);
            ans.push_back(curr);
            
            backtrack(nums,i+1,end,curr);
            
            curr.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> temp;
        ans.push_back({});
        backtrack(nums,0,nums.size(),temp);
        
        return ans;
    }
};