class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int i , n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> pq;
        
        pq.push_back(0);
        
        for(i=1;i<n;++i)
        {
            if(pq.front() < i - k)
                pq.pop_front();
            dp[i] = nums[i] + dp[pq.front()];
            while(pq.empty() == false && dp[pq.back()] <= dp[i])
                pq.pop_back();
            pq.push_back(i);
        }
        
        return dp[n-1];
    }
};