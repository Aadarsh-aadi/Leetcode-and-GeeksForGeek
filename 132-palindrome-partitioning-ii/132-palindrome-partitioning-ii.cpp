class Solution {
public:
    int minCut(string s) 
    {
        int n = s.size(),i,j,k,l;
        
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        
        // find palindrome
        for(l = 1; l <= n ; ++l)
        {
            for(i = 0 ; i <= n-l ; ++i)
            {
                j = i + l - 1;
                
                if(l == 1)
                {
                    isPal[i][j] = true;
                }
                else if(l == 2)
                {
                    isPal[i][j] = (s[i] == s[j]);
                }
                else
                {
                    isPal[i][j] = (s[i] == s[j]) && (isPal[i+1][j-1]);
                }
            }
        }
        
        // find minimum cut by dynamic programming
        // mcm type qs
        
        if(isPal[0][n-1] == true)
            return 0;
        
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(i=1;i<n;++i)
        {
            if(isPal[0][i] == true)
                dp[i] = 0;
            else{
                for(j = 0 ; j < i ; ++j)
                {
                    if(isPal[j+1][i] == true && 1 + dp[j] < dp[i])
                        dp[i] = 1 + dp[j];
                }
            }
        }
       
        return dp[n-1];
    }
};