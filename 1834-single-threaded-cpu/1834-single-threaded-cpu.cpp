class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // to sort on basis of shortest job time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> nextTask;
        
        // to sort on basis of enqueue time so that when CPU is idle we enter first coming job
         vector<array<int, 3>> sortedTasks;
        for (int i = 0; i < n; ++i) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int> tasksProcessingOrder;

        long long currTime = 0;
        int taskIndex = 0;
        
        while(taskIndex < n || nextTask.empty() == false)
        {
            if(nextTask.empty() == true && currTime < sortedTasks[taskIndex][0])
            {
                currTime = sortedTasks[taskIndex][0];
            }
            
            while(taskIndex < n && currTime >= sortedTasks[taskIndex][0])
            {
                 nextTask.push({sortedTasks[taskIndex][1], sortedTasks[taskIndex][2]});
                ++taskIndex;
            }
            
            auto pairTemp = nextTask.top();
            nextTask.pop();
            
            currTime += pairTemp.first;
            tasksProcessingOrder.push_back(pairTemp.second);
        }
        
         return tasksProcessingOrder;
    }
};