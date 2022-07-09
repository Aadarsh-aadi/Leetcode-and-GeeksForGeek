class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int i , n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        multiset<int> pq;
        
        pq.insert(nums[0]);
        
        for(i=1;i<n;++i)
        {
           if(i > k)
               pq.erase(pq.find(dp[i-k-1]));
            dp[i] = *pq.rbegin() + nums[i];
            pq.insert(dp[i]);
        }
        
        return dp[n-1];
    }
};