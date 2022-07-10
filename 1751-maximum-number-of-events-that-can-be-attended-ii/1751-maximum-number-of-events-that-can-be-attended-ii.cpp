class Solution {
public:
    vector<vector<int>> dp;
    int binary_search(vector<vector<int>>& events , int start , int end , int num)
    {
        int ans = -1 , mid;
        while(start<=end)
        {
            mid = start + (start - end)/2;
            if(events[mid][0] > num)
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return ans;
    }
    int recur(vector<vector<int>>& events , int idx , int k , int end)
    {
        if(idx == end || idx == -1)
            return 0;
        if(k == 0)
            return 0;
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        int i;
       for(i=idx+1;i<events.size();i++)
        {
            if(events[i][0]>events[idx][1])
            {
                break;
            }
        }
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