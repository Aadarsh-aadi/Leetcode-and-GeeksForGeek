// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSum(int n, vector<vector<int>> A)
    {
        // code here
        int i,j;
    int dp[n+1][2];
     dp[0][0] = dp[0][1] = 0;
     dp[1][0] = A[0][0];
     dp[1][1] = A[1][0];

     for(i=2;i<=n;++i)
     {
         //cout << i << endl;
         dp[i][0] =max(dp[i-1][0],(A[0][i-1] + max(dp[i-2][0],dp[i-2][1])));
         dp[i][1] =max(dp[i-1][1],(A[1][i-1] + max(dp[i-2][0],dp[i-2][1])));

         //cout << dp[i][0] <<" "<< dp[i][1] <<endl;
     }

     return max(dp[n][0],dp[n][1]);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }
        
        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends