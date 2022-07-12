// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    stack<int> s;
    void insertAtBottom(int x)
    {
        if(s.empty() == true)
        {
            s.push(x);
            return;
        }
        else
        {
            int y = s.top();
            s.pop();
            insertAtBottom(y);
            s.push(x);
        }
    }
    void reverse()
    {
        if(s.empty() == false)
        {
            int x = s.top();
            s.pop();
            reverse();
            insertAtBottom(x);
        }
    }
    vector<int> Reverse(stack<int> St)
    {
        s = St;
        reverse();
        vector<int> ans;
        while(s.empty() == false)
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends