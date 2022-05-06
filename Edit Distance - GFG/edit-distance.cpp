// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        
        int n = s.size() , m = t.size() , i ,j;
        
        vector<vector<int> > dp(n+1,vector<int>(m+1));
        
       
        
        for(i=0;i<=n;++i)
        {
            for(j=0;j<=m;++j)
            {
                if(i == 0 || j==0)
                    {
                        dp[i][j] = i+j;
                    }
                else if(s[i-1] == t[j-1])
                        dp[i][j] = dp[i-1][j-1];
                 else
                        dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) ;
                     
            }
        }
        
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends