// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
         vector<int> dp(n),dp1(n);
        int i,j;
        
        for(i=0;i<n;++i)
        {
            dp[i] = dp1[i] = mat[0][i];
        }
        
        for(i=1;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                dp[j] = dp1[j] + mat[i][j];
                if(j > 0)
                    dp[j] = max(dp[j] , dp1[j-1] + mat[i][j]);
                if(j < n-1)
                    dp[j] = max(dp[j] , dp1[j+1] + mat[i][j]);
            }
            
            dp1 = dp;
        }
        
        int mx = INT_MIN ;
        
        for(i=0;i<n;++i)
        {
            mx = max(mx , dp[i]);
        }
        
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends