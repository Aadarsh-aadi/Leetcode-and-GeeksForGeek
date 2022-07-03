class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
    {
         int i, j;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> busyServers;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        
        vector<int> ans(tasks.size());
        
        for(i = 0; i < servers.size(); i++){
            freeServers.push({servers[i], i});
        }
        
        int head = 0;
        for(i = 0; i < tasks.size(); i++){  
            while(!busyServers.empty() && busyServers.top()[0] <= i){
                vector<int> temp = busyServers.top();
                busyServers.pop();
                freeServers.push({temp[1], temp[2]});
            }
            
            while(head <= i && !freeServers.empty()){
                pair<int, int> p = freeServers.top();
                freeServers.pop();
                vector<int> temp{i + tasks[head], p.first, p.second};
                busyServers.push(temp);
                ans[head++] = p.second;
            }   
        }
        
        int time = tasks.size() - 1;
        
        while(head < tasks.size()){
            if(freeServers.empty()){
                time = busyServers.top()[0];
            }
            
            while(!busyServers.empty() && busyServers.top()[0] <= time){
                vector<int> temp = busyServers.top();
                busyServers.pop();
                freeServers.push({temp[1], temp[2]});
            }
            
            while(head < tasks.size() && !freeServers.empty()){
                pair<int, int> p = freeServers.top();
                freeServers.pop();
                vector<int> temp{time + tasks[head], p.first, p.second};
                busyServers.push(temp);
                ans[head++] = p.second;
            }   
        }
        
        return ans;
    }
};