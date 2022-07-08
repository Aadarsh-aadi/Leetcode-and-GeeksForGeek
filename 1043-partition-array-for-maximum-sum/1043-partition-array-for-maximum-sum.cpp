class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n];
       
        memset(dp,0,sizeof(dp));
        
        dp[0] = arr[0];
        int maxi = arr[0];
        //filling 1-(k-1) of dp array
        for(int i=1;i<k;i++)
        {
            maxi = max(maxi,arr[i]);
            dp[i] = maxi*(i+1);  
        }
        
        for(int i=k;i<n;i++)
        {
            int maxi = arr[i];//MINIMIUM VALUE
            for(int j=1;j<=k;j++)
            {
               maxi = max(maxi,arr[i-j+1]);
                dp[i] = max(dp[i],dp[i-j] + maxi*j);
            }
        }
        
        return dp[n-1];
        
    
    }
};