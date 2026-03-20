#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int sum = n + m;
        vector<int> oneRow = vector<int>(n,0);
        vector<int> oneCol = vector<int>(m,0);

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j]){
                    oneRow[i]++;
                    oneCol[j]++;
                }
            }
        }

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = 2 * (oneRow[i] + oneCol[j]) - (sum);
            }
        }

        return grid;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();