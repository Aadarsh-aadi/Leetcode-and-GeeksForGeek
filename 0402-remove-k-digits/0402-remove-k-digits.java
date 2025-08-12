class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Integer> s = new Stack<>();
        int i, n = num.length(), j;
        for(i = 0; i < n ; ++i) {
            j = num.charAt(i) - '0';
            while (!s.empty() && j < s.peek() && k > 0 ) {
                s.pop();
                k--;
            }   
            s.push(j);
        }

        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        StringBuilder ans = new StringBuilder();
        for(int d : s){
            ans.append(d);
        }
        i = 0;
        while(i < ans.length() && ans.charAt(i) == '0')
            i++;
        
        return (i==ans.length())? "0" : ans.substring(i);


    }
}