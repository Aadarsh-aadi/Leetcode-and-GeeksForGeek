class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        // 21 26 31 33 40
        //       ||
        // smash || remaining array 
        //       ||
        // 40 26 -> 14 21 31 33
        // 33 21 -> 12 14 31
        // 31 14 -> 12 17
        // 12 17 -> 5
        
        /*
        expand each term and you will notice that this question turns to partiton problem i.e., partition the array in two subset such that difference between sum of both subset is minimum.
        
        (17-12) ⇒ (31 - 14) - (33 - 21) ⇒ (31 - (40 - 26 ) ) - (33 - 21 )

         ⇒ ( 21 + 26 + 31 ) - ( 40 + 33 )  ⇒    5
        
        */
        
          int sum = 0,i,j,n=arr.size();
	    for(i=0;i<n;++i)
	    {
	        sum+=arr[i];
	    }
	    
	    vector<int> dp(sum/2 + 1,0);
	    
	    for(i=0;i<n;++i)
	    {
	        for(j=sum/2;j>=arr[i];--j)
	        {
	            if(dp[j-arr[i]] == 1 || j == arr[i])
	             dp[j] = 1;
	        }
	    }
	    
	    for(i=sum/2;i>0;--i)
	    {
	        if(dp[i] == 1)
	        {
	            break;
	        }
	    }
	    
	    return sum - 2*i;
        
    }
};