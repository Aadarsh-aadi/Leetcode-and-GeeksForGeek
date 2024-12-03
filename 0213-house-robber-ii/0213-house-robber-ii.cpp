class Solution {
public:
    int robberFunc(vector<int>& nums , int l , int r){
        int n = r - l + 1;
        vector<int> dp(n);
        if(n == 1) return nums[l];
        dp[0] = nums[l];
        dp[1] = max(nums[l] , nums[l+1]);

        for(int i = 2 ; i < n ; ++i) {
            dp[i] = max(dp[i-1] , dp[i-2] + nums[l+i]);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int i , n = nums.size();
        if(n == 1) return nums[0];
        return max(robberFunc(nums,0,n-2) , robberFunc(nums,1,n-1));
    }
};