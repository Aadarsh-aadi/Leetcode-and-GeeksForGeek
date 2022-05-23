class TreeAncestor {
public:
    vector<vector<int>> up;
    int log ;

    TreeAncestor(int n, vector<int>& parent) 
    {
        log = 0;
        while((1<<log) <= n)
        {
            log++;
        }
        
        up = vector<vector<int>>(n,vector<int>(log,-1));
        
        int i,j;

        for(i=0;i<n;++i)
        {
            up[i][0] = parent[i];
        }
        for(j = 1; j<log;++j)
         {
                for(i=0;i<n;++i)
                    {
                        if(up[i][j-1] == -1)
                            continue;
                        up[i][j] = up[up[i][j-1]][j-1];
                    }
           }
    }
    
    int getKthAncestor(int node, int k) 
    {
       if(node == 0)
           return -1;
        for(int i=0;i<log;++i)
        {
            if((1<<i) & k)
            {
                node = up[node][i];
                if(node == -1)
                    return -1;
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */