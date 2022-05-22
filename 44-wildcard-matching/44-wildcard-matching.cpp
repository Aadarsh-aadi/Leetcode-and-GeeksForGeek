class Solution {
public:
    bool isMatch(string A, string B) 
    {
           int n = A.size() , m = B.size() , i , j;
    bool dp[n+1][m+1];
    memset(dp, false, sizeof(dp));
    
    dp[0][0]= true;

    for(j=1;j<=m;++j)
    {
        dp[0][j] = (B[j-1]=='*') && (dp[0][j-1]);
    }
    dp[0][0] = true;

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(B[j-1] == '?' || B[j-1] == A[i-1] )
            dp[i][j] = dp[i-1][j-1];

            else if(B[j-1] == '*')
            dp[i][j] = dp[i][j-1] || dp[i-1][j];

            else
            dp[i][j] = false;
        }
    }

    return dp[n][m];
    }
};