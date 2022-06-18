class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int l=1,r=1e6,mid,ans;
        while(l<=r)
        {
            int c=0;
            mid = l + (r-l)/2;
            for(auto a : nums)
            {
                c += (a/mid);
                if(a%mid)
                    c++;
                if(c > threshold)
                    break;
            }
            
            if(c <= threshold)
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