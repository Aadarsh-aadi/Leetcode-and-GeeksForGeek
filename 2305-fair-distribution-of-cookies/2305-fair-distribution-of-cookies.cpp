class Solution {
public:
    
    int distributeCookies(vector<int>& cookies, int k) 
    {
        int i , n = cookies.size() , j , mask , submask;
        int bitSize = 1<<n;
        
        vector<int> sum(bitSize,0);
        vector<vector<int>> dp(k+1,vector<int>(bitSize,INT_MAX)) ;
        
        for(mask=0;mask<bitSize;++mask)
        {

            for(j=0;j<n;++j)
            {
                if(mask & (1<<j))
                {
                    sum[mask] += cookies[j];
                }
            }
        }
        dp[0][0] = 0 ;
        for(i=1;i<=k;++i)
        {
            for(mask=0;mask<bitSize;++mask)
            {
                for(submask = mask ; submask ; submask = (submask-1)&mask)
                {
                    dp[i][mask] = min(dp[i][mask] , max(sum[submask] , dp[i-1][mask^submask]));
                }
            }
        }
        
        return dp[k][bitSize-1];
        
    }
};