class Solution {
    public String smallestSubsequence(String s) {
        int[] freq = new int[26];

        for(char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        boolean[] visited = new boolean[26];
        int top = -1, n = s.length();
        char[] charArr = new char[n];

        for(char c : s.toCharArray()) {
            --freq[c - 'a'];

            if(visited[c - 'a']) continue;

            while(top >= 0 && charArr[top] > c && freq[charArr[top] - 'a'] > 0) {
                visited[charArr[top] - 'a'] = false;
                --top;
            }

            charArr[++top] = c ;
            visited[c - 'a'] = true;
        }

        StringBuilder ans = new StringBuilder();

        for(int i = 0 ; i <= top ; ++i){
            ans.append(charArr[i]);
        }

        return ans.toString();
    }
}