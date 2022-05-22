class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.size() , m = p.size() , i ,j;
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;
        
        for(i=1;i<=m;++i)
            dp[0][i] = (dp[0][i-1]) && (p[i-1] == '*');
        
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(p[j-1] == '?' || p[j-1] == s[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};