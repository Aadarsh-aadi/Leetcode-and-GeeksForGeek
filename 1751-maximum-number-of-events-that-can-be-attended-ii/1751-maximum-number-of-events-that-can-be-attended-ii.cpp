class Solution {
public:
    vector<vector<int>> dp;
    int find(vector<vector<int>>&events,int start,int toFind)
    {
        int low=start;
        int high=events.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(events[mid][0]>toFind)
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
    int recur(vector<vector<int>>& events , int idx , int k , int end)
    {
        if(idx >= end || idx == -1)
            return 0;
        if(k == 0)
            return 0;
        if(dp[idx][k]!=-1)
            return dp[idx][k];
       
        int i=find(events,idx+1,events[idx][1]);
        
        int included = events[idx][2] + recur(events,i,k-1,end);
        int notIncluded = recur(events,idx+1,k,end);
        
        return dp[idx][k] = max(included,notIncluded);
    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
         sort(events.begin(),events.end(),[]
            (vector<int>&a,vector<int>&b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return  a[0]<b[0];
             }
            );
        int n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        return recur(events,0,k,n);
    }
};