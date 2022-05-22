class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.size(), m = p.size() ,i,j;
        
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
    
    dp[0][0]= true;

    for(j=2;j<=m;++j)
    {
        dp[0][j] = (p[j-1]=='*') && (dp[0][j-2]);
    }
        
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(p[j-1] == '.' || p[j-1] == s[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(j>1 && p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }
                else
                    dp[i][j] = false;
            }
        }
        
        /*for(i=0;i<=n;++i,cout << endl)
            for(j=0;j<=m;++j,cout <<" ")
                cout << dp[i][j];*/
        
        return dp[n][m];
        
    }
};