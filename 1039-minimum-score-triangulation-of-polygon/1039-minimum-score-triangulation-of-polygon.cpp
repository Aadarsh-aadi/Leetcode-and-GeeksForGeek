class Solution {
public:
    vector<vector<int>> memo;
    int dp(int start, int end , vector<int> values)
    {
       // cout << start << " "<< end << endl;
        if(end-start<=1)
            return 0;
        if(memo[start][end] != INT_MAX)
        {
            return memo[start][end];
        }
        
        for(int i = start+1 ; i < end ; ++i)
        {
            int temp = dp(start,i,values) +
                       dp(i,end,values) + 
                    (values[start]*values[i]*values[end]);
            
            memo[start][end] = min(memo[start][end],temp);
            
        }
        
        return memo[start][end];
    }
    
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size(),i,j;
        memo = vector<vector<int>>(n,vector<int>(n,INT_MAX));
        return dp(0,n-1,values);
    }
};