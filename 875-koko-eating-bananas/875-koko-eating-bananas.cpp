class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l=1,r=1e9,mid,ans;
        while(l<=r)
        {
            int c=0;
            mid = l + (r-l)/2;
            for(auto a : piles)
            {
                c += (a/mid);
                if(a%mid)
                    c++;
                if(c > h)
                    break;
            }
            
            if(c <= h)
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