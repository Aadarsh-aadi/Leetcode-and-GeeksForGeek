class Solution {
public:
    int dp[16][1<<16];
    int solve(int index , vector<int> a , vector<int> b, int mask , int n)
    {
        if(index == n)
            return 0;
        if(dp[index][mask] != -1)
            return dp[index][mask];
        int j = INT_MAX;
        for(int i = 0 ; i < n ;++i)
        {
            if(mask&(1<<i))
            {
                j = min(j,(a[index]^b[i]) + solve(index+1,a,b,(mask^(1<<i)),n));
            }
        }
        
        return dp[index][mask] = j;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int n = nums1.size();
        
        return solve(0,nums1,nums2,((1<<n) - 1),n);
    }
};