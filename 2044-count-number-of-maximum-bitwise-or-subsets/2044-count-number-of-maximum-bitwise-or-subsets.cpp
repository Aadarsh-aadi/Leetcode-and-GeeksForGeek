class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        long long int bitLen,i,j,n = nums.size();
        long long int mx = 0 , count = 0 , orNum = 0;
        
        bitLen = 1<<n;
        
        for(i=0;i<n;++i)
            mx |= nums[i];
        
        for(i=1;i<bitLen;++i)
        {
            orNum = 0LL;
            for(j=0;j<n;++j)
            {
                if(i & (1<<j))
                {
                    orNum |= nums[j]; 
                }
            }
            //cout << orNum <<endl;
             if(mx == orNum)
            {
                count++;
            }
        }
        
        return count;
    }
};