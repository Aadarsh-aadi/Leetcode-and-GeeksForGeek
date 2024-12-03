class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i , n = nums.size() , posIdx = 0, negIdx = 0;
        vector<int> ans(n);

        for(i = 0 ; i < n ; ++i){
            if(nums[i] < 0){
                ans[(2*negIdx) + 1] = nums[i];
                ++negIdx;
            } else {
                ans[2*posIdx] = nums[i];
                ++posIdx;
            }
        }
        
        return ans;
    }
};