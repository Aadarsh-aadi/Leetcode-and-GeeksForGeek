class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        long long int bitLen,i,j,n = nums.size();
        long long int mx = 0 , count = 0 , orNum;
        
        bitLen = 1<<n;
        
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
            if(orNum > mx)
            {
                mx = orNum;
                count = 1;
            }
            else if(mx == orNum)
            {
                count++;
            }
        }
        
        return count;
    }
};