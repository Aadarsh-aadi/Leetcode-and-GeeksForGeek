// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isPatternPresent(string S, string P) {
        // code here
         if(P.length() > S.length()+1) return (0);
       if(P.find("^") != -1){
           
           for(int i = 0,j = 1; i < S.length() && j < P.length(); i++,j++){
               if(S[i] != P[j]) return (false);
           }
           
           return (true);
       }
       else if(P.find("$") != -1){
           
           for(int i = S.length()-1, j = P.length()-2; i >= 0 && j >= 0; i--,j--){
               if(S[i] != P[j]) return (false);
           }
           
           return (true);
       }
       
       return S.find(P) != -1 ? 1 : 0; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string P,S;

        cin>>P;
        cin>>S;

        Solution ob;
        cout << ob.isPatternPresent(S,P) << endl;
    }
    return 0;
}  // } Driver Code Ends