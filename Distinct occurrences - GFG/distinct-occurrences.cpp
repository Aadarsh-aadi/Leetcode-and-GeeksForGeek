// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string A, string B)
    {
      //Your code here
      int i,j,n = A.size() , m = B.size(),mod=1e9+7;

    if(m > n)
    return 0;
    
    long long int dp[m+1][n+1];

    for(i=0;i<=m;++i)
    dp[i][0] = 0;

    for(i=0;i<=n;++i)
    dp[0][i] = 1;

    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(A[j-1]!=B[i-1])
            {
                dp[i][j] = (dp[i][j-1])%mod;
            }
            else{
                dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%mod;
            }
        }
    }

return ((int)dp[m][n]);
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends