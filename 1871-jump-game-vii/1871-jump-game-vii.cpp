class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n = s.size() , i ;
        int window = 0;
        vector<bool> dp(n);
        dp[0] = true;
        
        for(i=1;i<n;++i)
        {
            if(i >= minJump)
                window = window + dp[i-minJump];
            if(i > maxJump)
                window = window - (dp[i-maxJump-1]);
            
            dp[i] = (window > 0 && s[i] == '0');
           // cout << window << " " <<dp[i] << endl;
        }
        
        return dp[n-1];
    }
};