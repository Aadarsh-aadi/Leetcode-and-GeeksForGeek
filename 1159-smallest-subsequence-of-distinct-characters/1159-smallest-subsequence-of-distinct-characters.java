class Solution {
    public String smallestSubsequence(String s) {
        int[] freq = new int[26];

        // Store Count of each element
        // This will help while popping the character from stack
        for(char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Keep a visited boolean array to skip
        // already present character in stack
        boolean[] visited = new boolean[26];

        // Implementing stack using array
        // This reduces time due to complexity of 
        // boxing and unboxing in Stack
        int top = -1, n = s.length();
        char[] charArr = new char[n];

        for(char c : s.toCharArray()) {
            // decrement the count of current character
            --freq[c - 'a'];

            // Skip already present character in stack
            if(visited[c - 'a']) continue;

            // Check if stack is empty and
            // if current character is smaller than stack top character and
            // if stack top character has another occurence left.
            while(top >= 0 && charArr[top] > c && freq[charArr[top] - 'a'] > 0) {
                // set visited flag for top character to false
                visited[charArr[top] - 'a'] = false;
                // pop the element from stack
                --top;
            }

            // push the current element on stack
            charArr[++top] = c ;
            // Mark characted as visited.
            visited[c - 'a'] = true;
        }
        
        // Build the answer.
        StringBuilder ans = new StringBuilder();

        for(int i = 0 ; i <= top ; ++i){
            ans.append(charArr[i]);
        }

        return ans.toString();
    }
}