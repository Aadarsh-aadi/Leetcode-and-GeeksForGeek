class Solution {
public:
    bool isPossible(vector<int> time,int trips,long long int val)
    {
        int i,n=time.size();
        long long c = 0;
        
        for(i=0;i<n;++i)
        {
            c += (val/time[i]);
            if(c >= trips)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
       long long int l=1,r,mid,ans;
       long low=INT_MAX;
       for(auto i:time){low=min(low,long(i));}
       r=totalTrips*low;
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