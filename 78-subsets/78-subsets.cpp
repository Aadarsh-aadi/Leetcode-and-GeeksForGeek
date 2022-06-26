class Solution {
public:
    vector<vector<int>> ans;
   
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int bitLen,n=nums.size(),i,j;
        bitLen = 1<<n;
        vector<int> temp;
        for(i=0;i<bitLen;++i)
        {
            temp.clear();
            for(j=0;j<n;++j)
            {
                if(i & (1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};