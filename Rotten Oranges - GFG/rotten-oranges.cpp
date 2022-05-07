// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
       int m=grid[0].size();
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               
               if(grid[i][j]==2){
                   q.push({i,j});
               }
           }
       }
       int count=0;
       int temp=q.size();
       
     while(!q.empty()){
         
         int counter=0;
         while(temp--){
         
         int i=q.front().first;
         int j=q.front().second;
         if(i-1>=0&&grid[i-1][j]==1){
             grid[i-1][j]=2;
             q.push({i-1,j});
             counter++;
            
         }
         if(i+1<n&&grid[i+1][j]==1){
             grid[i+1][j]=2;
             q.push({i+1,j});
             counter++;
            
         }
         if(j-1>=0 && grid[i][j-1]==1){
             grid[i][j-1]=2;
             q.push({i,j-1});
             counter++;
            
         }
         if(j+1<m && grid[i][j+1]==1){
             grid[i][j+1]=2;
             q.push({i,j+1});
             counter++;
             
         }
         
         q.pop();
     }
     if(q.empty())
      break;
     count++;
         
   
     temp=counter;
         
     }
     
     for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               
               if(grid[i][j]==1){
                   return -1;
               }
           }
       }
     
     return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends