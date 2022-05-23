class Solution {
public:
    int longestPalindromeSubseq(string A) 
    {
         int i,j,l,n = A.size();
        int dp[n][n];
        
        for(i=0;i<n;++i)
        {
            dp[i][i] = 1;
            if(i < n-1 && A[i] == A[i+1])
                dp[i][i+1] = 2;
            else if(i < n-1)
                dp[i][i+1] = 1;
        }
        
        for(l = 3; l <= n; ++l)
        {
            for(i=0;i<=n-l;++i)
            {
                j = i + l - 1;
                if(A[i] == A[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }
};