class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size() , i ;
        multiset<int> pq;
        for(i=0;i<k;++i)
        {
            pq.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*pq.rbegin());
        
        for(i=k;i<n;++i)
        {
            pq.erase(pq.find(nums[i-k]));
            pq.insert(nums[i]);
            ans.push_back(*pq.rbegin());
        }
        
        return ans;
    }
};