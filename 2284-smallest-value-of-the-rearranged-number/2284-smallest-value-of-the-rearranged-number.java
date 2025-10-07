class Solution {

    public long smallestNumber(long num) {
        if(num == 0) {
            return 0;
        }

        boolean isNegative = (num < 0)? true : false;
        if(isNegative){
            num = num * (-1);
        }

        char[] arr = String.valueOf(num).toCharArray();
        Arrays.sort(arr);
        int n = arr.length;
        long ans = 0;

        if(isNegative) {
            for(int i = n-1 ; i >= 0 ; --i){
                ans = ans * 10 + (arr[i]-'0');
            }
            ans = ans * (-1);
        } else {
            // find first non-zero digit
            int j = 0;
            while (j < n && arr[j] == '0') {
                ++j;
            }
            char temp = arr[0];
            arr[0] = arr[j];
            arr[j] = temp;

            // convert to long
            for(int i = 0 ; i < n ; ++i) {
                ans = ans * 10 + (arr[i] - '0');
            }
        }

        return ans;
        
    }
}