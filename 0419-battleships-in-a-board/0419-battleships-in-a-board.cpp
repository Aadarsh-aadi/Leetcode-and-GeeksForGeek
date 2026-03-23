class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int ans = 0;
        for(int i=0; i < n ; ++i){
            for(int j=0;j<m;++j){
                if(board[i][j]=='X'){
                    if(i+1 < n && board[i+1][j]=='X'){}
                    else if(j+1 < m && board[i][j+1]=='X'){
                        while(j+1 < m && board[i][j+1]=='X'){
                            j++;
                        }
                        ans++;
                    } else{
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();