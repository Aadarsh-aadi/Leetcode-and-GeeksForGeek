// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.size(),i,j,mod=1e9+7,l;
       
      vector<vector<unsigned long long int>> dp(n,vector<unsigned long long int>(n,0));
       
       for(i=0;i<n;++i)
       {
           dp[i][i] = 1;
       }
       
       for(l=2;l<=n;++l)
       {
           for(i=0;i<=n-l;++i)
           {
               j = i+l-1;
              if(str[i] == str[j])
              dp[i][j] = (dp[i+1][j]%mod + dp[i][j-1]%mod + 1+mod)%mod;
              else
              dp[i][j] = (((dp[i+1][j]%mod+dp[i][j-1]%mod)%mod) - dp[i+1][j-1]%mod + mod)%mod;
              
              dp[i][j]+=mod;
              dp[i][j]%=mod;
           }
       }
       dp[0][n-1]+=mod;
       dp[0][n-1]%=mod;
       return (long long int) (dp[0][n-1])%mod;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends