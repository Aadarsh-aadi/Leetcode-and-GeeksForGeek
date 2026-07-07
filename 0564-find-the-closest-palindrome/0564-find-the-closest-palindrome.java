class Solution {
    public String nearestPalindromic(String n) {
        int len = n.length();
        int mid = (len+1)/2;
        long firstHalf = Long.parseLong(n.substring(0,mid));

        List<Long> posiAns = new ArrayList<>();

        posiAns.add(toPalindrome(firstHalf-1, len%2==0));
        posiAns.add(toPalindrome(firstHalf, len%2==0));
        posiAns.add(toPalindrome(firstHalf+1, len%2==0)); 
        posiAns.add((long)Math.pow(10,len-1) - 1);
        posiAns.add((long)Math.pow(10,len)+1);

        long ans = 0 , maxDiff=Long.MAX_VALUE, num = Long.parseLong(n);
        
        for(long posi : posiAns){
            if(posi == num) continue;
            if(Math.abs(num-posi) < maxDiff){
                ans = posi;
                maxDiff=Math.abs(num-posi);
            } else if(Math.abs(num-posi) == maxDiff) {
                ans = Math.min(posi,ans);
            }
        }

        return String.valueOf(ans);
    }

    private long toPalindrome(long num, boolean even) {
        long ans = num;
        if(!even) num = num/10;
        while(num > 0){
            ans = ans*10 + (num%10);
            num = num/10;
        }

        return ans;
    }
}