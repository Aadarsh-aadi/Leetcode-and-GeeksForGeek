class Solution {
public:
    int dp[1<<15][16];
    int solve(int mask , vector<int>& t , int remTime , int n , int k)
    {
        if(mask == 0)
            return 1;
        if(dp[mask][remTime] != -1)
            return dp[mask][remTime];
        
        int j = INT_MAX ;
        
        for(int i=0;i<n;++i)
        {
            if(mask&(1<<i))
            {
                if(remTime >= t[i])
                {
                    j = min(j,solve(mask^(1<<i),t,remTime - t[i] , n , k));
                }
                else{
                    j = min(j,1+solve(mask^(1<<i),t,k-t[i],n,k));
                }
            }
        }
        
        return dp[mask][remTime] = j;
    }
    int minSessions(vector<int>& tasks, int sessionTime) 
    {
        memset(dp,-1,sizeof(dp));
        int n = tasks.size();
        return solve((1<<n)-1,tasks,sessionTime,n,sessionTime);
    }
};