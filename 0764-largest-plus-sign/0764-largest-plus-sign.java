class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        Set<Integer> ban = new HashSet<>();
        int[][] dp = new int[n][n];

        for(int[] mine : mines){
            ban.add(mine[0]*n + mine[1]);
        }

        int ans=0, cnt;
        
        for (int r = 0 ; r < n ; ++r){
            cnt = 0;
            for(int c = 0 ; c < n ; ++c) {
                cnt = (ban.contains(r*n + c))? 0 : cnt + 1;
                dp[r][c] = cnt;
            }

            cnt = 0;
            for (int c = n-1 ; c >= 0 ; --c) {
                cnt = (ban.contains(r*n + c)) ? 0 : cnt + 1;
                dp[r][c] = Math.min(cnt, dp[r][c]);
            }
        }

        for(int c = 0 ; c < n ; ++c){
            cnt = 0;
            for(int r = 0 ; r < n ; ++r){
                cnt = (ban.contains(r*n + c)) ? 0 : cnt + 1;
                dp[r][c] = Math.min(cnt, dp[r][c]);
            }

            cnt = 0;
            for(int r = n-1 ; r>=0 ; --r) {
                cnt = (ban.contains(r*n + c)) ? 0 : cnt + 1;
                dp[r][c] = Math.min(cnt, dp[r][c]);
                ans = Math.max(ans, dp[r][c]);
            }
        }

        return ans;
    }
}