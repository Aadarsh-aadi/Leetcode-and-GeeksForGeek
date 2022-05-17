// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    int minSum(int arr[], int n){
        //Write your code here
        vector<int> dp(n);
      
        int i,mn;
        for(i=0;i<(min(n,4));++i)
        {
           dp[i] = arr[i];
        }
        for(i=4;i<n;++i)
            dp[i] = arr[i]+ min(min(dp[i - 1], dp[i - 2]),
                             min(dp[i - 3], dp[i - 4]));
 
        mn = dp[n-1];
        
        for(i=n-2;i>=(max(0,n-4));--i)
        {
            mn = min(mn,dp[i]);
        }
        
        return mn;
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends