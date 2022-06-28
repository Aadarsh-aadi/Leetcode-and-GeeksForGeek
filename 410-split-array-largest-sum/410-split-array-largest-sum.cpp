class Solution {
public:
    bool bs(int mid , vector<int>& nums , int k)
    {
        int c = 1 , curr = 0;
        
        for(auto n : nums)
        {
            if(n > mid)
                return false;
            if(curr + n > mid)
            {
                c++;
                curr = n;
            }
            else{
                curr += n;
            }
        }
        
        return (c <= k);
    }
    int splitArray(vector<int>& nums, int m) 
    {
        int i,n=nums.size(),sum=0;
        
        for(i=0;i<n;++i)
        {
            sum += nums[i];
        }
        
        
        int l = 0 , r = sum , ans , mid;
        
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(bs(mid,nums,m) == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};