class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int i,j,n=nums.size(),bitLen;
        sort(nums.begin(),nums.end());
        bitLen = 1<<n;
        ans.push_back({});
        map<string,int> mp;
        vector<int> temp;
        for(i=1;i<bitLen;++i)
        {
            temp.clear();
            string s="";
                for(j=0;j<n;++j)
                {
                    if(i & (1<<j))
                    {
                       s+=(nums[j]-'0');
                       temp.push_back(nums[j]);      
                    }

                }
            if(temp.size() && mp.find(s) == mp.end())
            {
                mp[s] = 99;
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};