class Solution {
public:
    void merge(vector<int>& nums, int left , int mid , int right)
    {
        int p1 = left , p2 = mid+1 , i , j;
        vector<int> temp;
        while(p1 <= mid && p2 <= right)
        {
            if(nums[p1] <= nums[p2])
            {
                j = nums[p1];
                p1++;
            }
            else
            {
                j = nums[p2];
                p2++;
            }
            
            temp.push_back(j);
        }
        
        while(p1 <= mid)
        {
            temp.push_back(nums[p1]);
            p1++;
        }
        
        while(p2 <= right)
        {
            temp.push_back(nums[p2]);
            p2++;
        }
        
        for(j = left , i = 0 ; j <= right ; ++j,++i)
        {
            nums[j] = temp[i];
        }
    }
    void mergesort(vector<int>& nums, int left , int right)
    {
        if(left < right)
        {
            int mid = left + (right - left)/2;
            mergesort(nums,left,mid);
            mergesort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int  start = 0 , end = nums.size() - 1;
        mergesort(nums,start,end);
        
        return nums;
    }
};