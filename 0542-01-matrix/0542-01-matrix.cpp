class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        static constexpr int dir[] = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        int n = mat.size(), m = mat[0].size(),dist = 0;
        int i,j,r,c,sz,r1,c1;
        for(i = 0 ; i < n ; ++i){
            for(j = 0 ; j < m ; ++j){
                if(!mat[i][j]){
                    q.push({i,j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            sz = q.size();
            ++dist;
            while(sz--){
                r = q.front().first;
                c = q.front().second;
                q.pop();
                for(i = 0 ; i < 4 ; ++i){
                    r1 = r + dir[i];
                    c1 = c + dir[i+1];
                    
                    if((unsigned)r1 < (unsigned)n &&
                        (unsigned)c1 < (unsigned)m &&
                        mat[r1][c1]== -1){
                            mat[r1][c1] = dist;
                            q.push({r1,c1});
                        }
                }
            }
        }

        return mat;
    }
};