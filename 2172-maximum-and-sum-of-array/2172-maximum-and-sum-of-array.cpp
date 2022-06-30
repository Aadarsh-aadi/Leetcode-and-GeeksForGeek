class Solution {
public:
    int dp[18][1<<18];
    int solve(int mask , int index , vector<int>& nums , int slots , int n)
    {
        if(index == n)
            return 0;
        if(dp[index][mask] != -1)
            return dp[index][mask];
        
        int mn = INT_MIN;
        for(int j=0;j<(2*slots);++j)
        {
            if(mask&(1<<j))
                continue;
            int temp = nums[index]&((j/2) + 1);
            mn = max(mn,temp + solve(mask^(1<<j),index+1,nums,slots,n));
        }
        
        return dp[index][mask] = mn;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums,numSlots,nums.size());
        
    }
};