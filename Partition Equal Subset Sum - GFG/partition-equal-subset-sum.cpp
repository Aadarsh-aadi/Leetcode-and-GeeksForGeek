// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int i,j,sum=0;
        
        // get the sum
        for(i=0;i<n;++i)
        {
            sum += arr[i];
        }
        
        
        
        if(sum%2)
          return 0;
        
        vector<bool> dp(sum/2 + 1,false);
        
        dp[0] = true;
        
        for(i=0;i<n;++i)
        {
            for(j=sum/2 ;j>=arr[i];--j)
            {
                dp[j] = dp[j] or dp[j-arr[i]];
            }
        }
        
        return dp[sum/2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends