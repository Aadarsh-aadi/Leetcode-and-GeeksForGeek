class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(events.begin(),events.end(),[]
            (vector<int>&a,vector<int>&b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return  a[0]<b[0];
             }
            );
        int i = 0 , n = events.size() , d = 0 , res = 0;
        
        while(pq.empty() == false || i<n)
        {
            if(pq.empty() == true)
                d = events[i][0];
           // cout << events[i][0] << " "<< events[i][1] << endl;
            while(i<n && events[i][0] <= d)
                pq.push(events[i++][1]);
            pq.pop();
            res++;
            d++;
            while(pq.empty() == false && pq.top() < d)
                pq.pop();
        }
        
        return res;
    }
};