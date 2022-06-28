class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {    
    long sum = 0; // calculate the total sum first
    for (const int& num : nums)
      sum += num;
    
    int way = 0;
    long curSum = 0; // keep tracking the current sum
    for (int i = 0; i < nums.size() - 1; i++) {
      curSum += nums[i];
      if (curSum >= sum - curSum)
        way++;
    }
    
    return way;
  }
};