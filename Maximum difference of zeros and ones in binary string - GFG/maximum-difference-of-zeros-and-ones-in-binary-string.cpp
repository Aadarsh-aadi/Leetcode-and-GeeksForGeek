// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int n = s.size(),i,j = -1;
	    vector<int> dp(n);
	    
	dp[0] = (s[0]=='0')? 1: 0;
	j = (s[0] == '0') ? 1 : -1;
	   // cout << dp[0] <<endl;
	    
	    for(i=1;i<n;++i)
	    {
	        if(s[i] == '0')
	        {
	            dp[i] = dp[i-1] + 1;
	             j = max(j,dp[i]);
	        }
	        else
	        {
	            if(dp[i-1] <= 0){}
	            else
	            dp[i] = dp[i-1] - 1;
	        }
	        //cout << dp[i]<<endl;
	       
	    }
	    
	    return j;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends