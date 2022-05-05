// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        // code here 
        // dp[i] will store if num formed from i to end is divisible by b
        
        string s1 = "" , s2 = S ;
        s1+=S[0];
        s2.erase(s2.begin());
        
        int i,n = S.size() ;
        
        for(i=0;i<n-1;++i)
        {
            if(stoi(s1)%a == 0 && stoi(s2)%b == 0)
            {
                return s1 + " " + s2;
            }
            
            s1 += S[i+1];
            s2.erase(s2.begin());
        }
        
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends