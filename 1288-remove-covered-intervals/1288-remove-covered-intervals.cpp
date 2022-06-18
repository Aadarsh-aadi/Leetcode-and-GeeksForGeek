class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
       sort(intervals.begin(),intervals.end());
        int i,n=intervals.size(),c,end = intervals[0][1],start=intervals[0][0];
        c=n;
        
        for(i=1;i<n;++i)
        {
            if(end < intervals[i][0])
            {
                start=intervals[i][0];
                end = intervals[i][1];
            }
            else if(end < intervals[i][1])
            {
                if(start == intervals[i][0])
                    c--;
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                c--;
            }
        }
        
        return c;
    }
};