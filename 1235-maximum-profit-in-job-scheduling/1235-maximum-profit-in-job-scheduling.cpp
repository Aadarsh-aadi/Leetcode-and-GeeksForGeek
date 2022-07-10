class Solution {
public:
    vector<int> dp;
    int find(vector<vector<int>>&events,int start,int toFind)
    {
        int low=start;
        int high=events.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(events[mid][0]>=toFind)
            {
                ans=mid;
              high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
       // cout<<ans<<endl;
        return ans;
        
    }
    int recur(vector<vector<int>>& events , int idx , int end)
    {
        if(idx >= end || idx == -1)
            return 0;
       
        if(dp[idx]!=-1)
            return dp[idx];
       
        int i=find(events,idx+1,events[idx][1]);
        
        int included = events[idx][2] + recur(events,i,end);
        int notIncluded = recur(events,idx+1,end);
        
        return dp[idx] = max(included,notIncluded);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for(int i=0; i<n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end(), []
            (vector<int>&a,vector<int>&b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return  a[0]<b[0];
             });
        
        dp = vector<int>(n+1,-1);
        return recur(jobs,0,n); 
    }
};