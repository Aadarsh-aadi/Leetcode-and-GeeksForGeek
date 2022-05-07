// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
public:
    string binaryPalindrome(int n,int k)
    {
       // Complete the function
       string ans="";
       
       if(k>=n)
       {
           ans+='1';
           
           while(n > 2)
           {
               ans+="0";
               n--;
           }
           
           ans+="1";
           
           return ans;
       }
       
       for(int i=1;i<=n;++i)
       {
           if(i%k == 1 || (i%k) == (n%k))
           ans+="1";
           else
           ans+="0";
       }
       
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        Solution obj;
        cout << obj.binaryPalindrome(n,k) << endl; 
    }
    return 0;
}
  // } Driver Code Ends