// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int mx = 0,i,j;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(mat[i-1][j-1] == 1)
                {
                    dp[i][j] = 1+min(min(dp[i][j-1] , dp[i-1][j] ), dp[i-1][j-1]);
                    mx = max(dp[i][j],mx);
                }
            }
        }
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends