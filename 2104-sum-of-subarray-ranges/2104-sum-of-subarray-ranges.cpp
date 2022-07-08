class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long int i , n = nums.size() , j , k;
        stack<long long> s;
        long long int res = 0LL;
        //find max 
        for(i=0;i<=n;++i)
        {
            while(s.empty() == false && nums[s.top()] < (i==n? 2e9 : nums[i]))
            {
                j = s.top() ;
                s.pop();
                k = (s.empty() == true) ? -1 : s.top();
                res += (long long int)nums[j] * (i-j) * (j-k);
                //cout << res << endl;
            }
            s.push(i);
        }
       
        s.pop();
        
        //min 
        for(i=0;i<=n;++i)
        {
            while(s.empty() == false && nums[s.top()] > (i==n? -2e9 : nums[i]))
            {
                j = s.top() ;
                s.pop();
                k = (s.empty() == true) ? -1 : s.top();
                res -= (long long int)nums[j] * (i-j) * (j-k);
            }
            s.push(i);
        }
        
        return res;
    }
};