class Solution {
public:
     vector<long long int> dp;
    long long int find(vector<vector<int>>&events,int start,int toFind)
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
    long long int recur(vector<vector<int>>& events , int idx , int end)
    {
        if(idx >= end || idx == -1)
            return 0;
   
        if(dp[idx]!=-1)
            return dp[idx];
       
       int i=find(events,idx+1,events[idx][1]);
        
       long long int included = events[idx][1] - events[idx][0] + events[idx][2] + recur(events,i,end);
       long long  int notIncluded = recur(events,idx+1,end);
        
        return dp[idx] = max(included,notIncluded);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& events) 
    {
         int n1 = events.size();
        sort(events.begin(),events.end(),[]
            (vector<int>&a,vector<int>&b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return  a[0]<b[0];
             }
            );
        dp = vector<long long int>((n1)+1,-1);
        return recur(events,0,n1);
    }
};