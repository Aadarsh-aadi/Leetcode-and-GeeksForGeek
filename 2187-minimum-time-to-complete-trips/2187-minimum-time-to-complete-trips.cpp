class Solution {
public:
    bool isPossible(vector<int> time,int trips,long long int val)
    {
        int i,n=time.size();
        long long c = 0;
        
        for(i=0;i<n;++i)
        {
            c += (val/time[i]);
        }
        return (c >= trips);
    }
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
       long long int l=1,r=1e14,mid,ans;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(isPossible(time,totalTrips,mid)==true)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
            
        }
        return ans;
        
    }
};