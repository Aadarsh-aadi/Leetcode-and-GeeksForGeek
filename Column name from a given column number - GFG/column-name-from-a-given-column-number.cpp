// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        int temp=n,i,j=0;
        int arr[20];
        
        while(temp)
        {
            arr[j++] = temp%26;
            temp = temp/26;
        }
        
        for(i=0;i<j-1;++i)
        {
            if(arr[i]<=0)
            {
                arr[i]+=26;
                arr[i+1]--;
            }
        }
        string ans="";
        char ch;
        for(i=0;i<j;++i)
        {
           if(arr[i] > 0)
           {
               ch = 'A' + (arr[i]-1);
               ans+=ch;
           }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends