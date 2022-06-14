class Solution {
public:
    int dp[201][201];
    vector<int> x={1, 0, -1, 0};
    vector<int> y={0, -1, 0, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int n=matrix.size(), m=matrix[0].size(), ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=max(ans, 1+dfs(matrix, i, j));
        return ans;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int temp=0;
        for(int k=0;k<4;k++){
            int dx=i+x[k], dy=j+y[k];
            if(dx<0||dx>=matrix.size()||dy<0||dy>=matrix[0].size())
                continue;
            if(matrix[dx][dy]>matrix[i][j])
                temp=max(temp, 1+dfs(matrix, dx, dy));
        }
        return dp[i][j]=temp;
    }
};