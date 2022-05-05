// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        
        int c = 0,n=arr.size();
        
        for(int i=0;i<n;++i)
        {
            c+=arr[i];
        }
        
        if(sum > c)
        return false;
        
        if(sum == c)
        return true;
        
         bool dp[n+1][sum+1];
        
        for(int i=0;i<=sum;++i)
        dp[0][i] = false;
        
        for(int i=0;i<=n;++i)
        dp[i][0] = true;
        
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=sum;++j)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends