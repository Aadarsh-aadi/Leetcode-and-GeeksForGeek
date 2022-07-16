class Solution {
public:
    vector<int> dp = vector<int>(21,-1);
    int numTrees(int n) 
    {
        if(n <= 1)
            return 1;
        int c = 0 , j;
        for(int i = 1 ; i <= n ; ++i)
        {
            if(dp[i-1] != -1)
            {
                j = dp[i-1];
            }
            else
            {
                j = numTrees(i-1);
            }
            
            if(dp[n-i]!= -1)
            {
                j *= dp[n-i];
            }
            else
            {
                j *= numTrees(n-i);
            }
            
            c+=j;
        }
        
        return dp[n] = c;
    }
};