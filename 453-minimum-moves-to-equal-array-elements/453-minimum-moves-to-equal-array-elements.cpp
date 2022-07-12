class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size() , sum = 0 , mn = INT_MAX;
        
        for(auto a : nums)
        {
            sum += a;
            mn = min(mn,a);
        }
        
        return sum - n*mn;
    }
};