// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) 
    {
        // code here
        int i,n = s.size(),mx = 0;
        
        stack<int> stk;
        //base index to start new valid substring
        stk.push(-1);
        
        for(i=0;i<n;++i)
        {
            if(s[i] == '(')
            stk.push(i);
            else{
                if(stk.empty() == false)
                {
                    stk.pop();
                }
                
                if(stk.empty() == false)
                {
                    mx = max(mx,i - stk.top());
                }
                else
                {
                    stk.push(i);
                }
            }
        }
        
        return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends