class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        int i , n = nums.length ;
        int etr = n - k;
        Stack<Integer> s = new Stack<>();
        s.push(nums[0]);
        for(i = 1 ; i < n ; ++i) {
            while(etr > 0 && !s.empty() && nums[i] < s.peek()) {
                s.pop();
                --etr;
            }
            s.push(nums[i]);
        }

        while(etr > 0){
            s.pop();
            etr--;
        }
        int[] ans = s.stream()
                     .mapToInt(Integer::intValue)
                     .toArray();
        return ans;
    }
}