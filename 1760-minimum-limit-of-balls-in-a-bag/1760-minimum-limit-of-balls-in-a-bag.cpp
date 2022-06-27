class Solution {
public:
    bool bs(vector<int> nums , int k , int comp)
    {
        int c = 0;
        for(auto n : nums)
        {
            c += (n/comp);
            if(n%comp == 0)
                c--;
            if(c > k)
            {
                return false;
            }
        }
        
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int r = 1 , l=1 , mid , n = nums.size(),i ,ans;
        
        for(i=0;i<n;++i)
        {
            r = max(r,nums[i]);
        }
        
        while(l<=r){
            mid = l + (r-l)/2 ;
            
            if(bs(nums,maxOperations,mid) == true)
            {
                ans = mid;
                r = mid - 1 ;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return ans;
        
    }
};