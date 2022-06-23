class Solution {
public:
    int topologicalSort(vector<vector<int>>& graph,vector<int>& inDegree,vector<int>& time,int n)
    {
        int i;
        queue<int> q;
        vector<int> endTime(n+1,0);
        for(i=1;i<=n;++i)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
                endTime[i] = time[i-1];
            }
        }
        
        while(q.empty() == false)
        {
            int size = q.size();
        
            while(size--)
            {
                int node = q.front();
                q.pop();
                
                for(auto child : graph[node])
                {
                     endTime[child] = max(endTime[child],endTime[node]+time[child-1]);
                    inDegree[child]--;
                    if(inDegree[child] == 0)
                    { 
                        q.push(child);
                    }
                }
            }
            
        }
        
        return *max_element(endTime.begin(),endTime.end());
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<vector<int>> graph(n+1);
        int i , r=relations.size() , x , y;
        vector<int> inDegree(n+1,0);
        for(i=0;i<r;++i)
        {
               x = relations[i][0];
               y = relations[i][1];
           // cout << x <<" "<<y;
               graph[x].push_back(y);
               inDegree[y]++;
        }
        
        return topologicalSort(graph,inDegree,time,n);
    }
};