class dsu {
    int *rank, *parent, n;
 
public:
    dsu(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
 
    int par(int x)
    {
        if (parent[x] != x) {
            parent[x] = par(parent[x]);
        }
        return parent[x];
    }
    void unions(int x, int y)
    {
        int xset = par(x);
        int yset = par(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};
 

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        dsu obj(n);
        obj.makeSet();
        vector<bool> ans;
        for(int i = 0; i < req.size();i++){
   int x= obj.par(req[i][0]);
                int y = obj.par(req[i][1]);
            bool b = true;
            for(int j = 0; j < res.size();j++){
                int x1 = obj.par(res[j][0]);
                int y1 = obj.par(res[j][1]);
                if((x==x1&&y==y1)||(x==y1&&y==x1)){
                    b = false;
                    break;
                }
            }
            if(b){
                ans.push_back(true);
                obj.unions(req[i][0],req[i][1]);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};