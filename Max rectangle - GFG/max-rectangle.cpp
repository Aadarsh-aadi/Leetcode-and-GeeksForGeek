// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int Area(vector<int>& h, int n)
    {
        int i = 0,temp,tp,ans=0;
        stack<int> s;
        while(i<n)
        {
            if(s.empty() == true || h[s.top()] <= h[i])
            {
                s.push(i++);
            }
            else
            {
                tp = s.top();
                s.pop();
                temp = h[tp] * ((s.empty()==true) ? i : i - s.top() - 1);
                ans = max(ans,temp);
            }
            
        }
        
        while(s.empty() == false)
        {
            tp = s.top();
            s.pop();
            temp = h[tp] * ((s.empty()==true) ? i : i - s.top() - 1);
            ans = max(ans,temp);
        }
        
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int i,j,temp,mx=0;
        
        vector<int> h(m,0);
        
        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                if(M[i][j] == 0)
                h[j] = 0;
                else
                h[j]++;
                //cout << h[j] ;
            }
            temp = Area(h,m);
            mx = max(temp,mx);
        }
        
        return mx;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends