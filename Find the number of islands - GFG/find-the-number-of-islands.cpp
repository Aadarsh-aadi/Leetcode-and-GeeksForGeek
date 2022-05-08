// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
  public :
  void dfs(int i,int j, vector<vector<char>>& v)
   {
       if(i<0 || j<0) return ;
       if(i>=v.size() || j>=v[0].size()) return;
       if(v[i][j]!='1') return; 
        v[i][j]='2';
       dfs(i-1,j-1,v); // lefg side up diagonally
       dfs(i-1,j,v); // up
       dfs(i-1, j+1,v); // right side up diagonally
       dfs(i,j-1,v); // left 
       dfs(i,j+1,v); // right 
       dfs(i+1, j-1,v); // left side down diagonally
       dfs(i+1, j,v); // down
       dfs(i+1, j+1,v); // right side down diagonally
       
   }
   
   int numIslands(vector<vector<char>>& v) {
       int count = 0;
       int r= v.size();
       int c= v[0].size();
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if(v[i][j]=='1')
               {
                   
                     dfs(i,j,v);
                       count++;
               
                   
               }
           }
       }
   
       return count;
                
      
   }
   
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends