// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0,i,j;
	    for(i=0;i<n;++i)
	    {
	        sum+=arr[i];
	    }
	    
	    vector<int> dp(sum/2 + 1,0);
	    
	    for(i=0;i<n;++i)
	    {
	        for(j=sum/2;j>=arr[i];--j)
	        {
	            if(dp[j-arr[i]] == 1 || j == arr[i])
	             dp[j] = 1;
	        }
	    }
	    
	    for(i=sum/2;i>0;--i)
	    {
	        if(dp[i] == 1)
	        {
	            break;
	        }
	    }
	    
	    return sum - 2*i;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends