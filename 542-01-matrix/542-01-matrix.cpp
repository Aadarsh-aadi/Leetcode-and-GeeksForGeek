class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int i,j,n = mat.size(),m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX-100000));
        
        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                if(mat[i][j] == 0)
                    ans[i][j] = 0;
                else
                {
                 if(i > 0)
                    ans[i][j] = min(ans[i][j],ans[i-1][j]+1);
                 if(j > 0)
                    ans[i][j] = min(ans[i][j],ans[i][j-1]+1);
                
                }
            }
        }
        
        for(i=n-1;i>=0;--i)
        {
            for(j=m-1;j>=0;--j)
            {
                if(mat[i][j] == 0)
                    ans[i][j] = 0;
                else
                {
                    if(i < n-1)
                        ans[i][j] = min(ans[i][j],ans[i+1][j]+1);
                    if(j < m-1)
                        ans[i][j] = min(ans[i][j],ans[i][j+1]+1);
                }
            }
        }
        
        return ans;
        
    }
};