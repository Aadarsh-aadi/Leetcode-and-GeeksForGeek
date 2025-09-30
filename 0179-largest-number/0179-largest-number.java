class Solution {
    public String largestNumber(int[] nums) {
        int n = nums.length;
        String[] numString = new String[n];
        for(int i = 0 ; i < n ; ++i){
            numString[i] = Integer.toString(nums[i]);
        }

        Arrays.sort(numString, (a,b) -> (b+a).compareTo(a+b));
        
        if(numString[0].equals("0")) {
            return "0";
        }

        StringBuilder ans = new StringBuilder();
        for(String s : numString) {
            ans.append(s);
        }

        return ans.toString();
    }
}