class Solution {
public:
    string largestNumber(vector<int>& cost, int target) 
    {
        vector<int> maxDigit(target+1,INT_MIN);
        int i , j ;
        maxDigit[0] = 0;
        for(i = 1 ; i<=target ;++i)
        {
            for(j = 0 ; j <= 8 ; ++j)
            {
                if(cost[j] <= i)
                    maxDigit[i] = max(maxDigit[i] , maxDigit[i-cost[j]] + 1);
                    
            }
            
            //cout << maxDigit[i] << " "<<i << endl;
        }
        
        if(maxDigit[target] < 0)
            return "0";
        
        string ans;
        
        for(i = 8 ; i >= 0 ; --i)
        {
            while(target >= cost[i] && maxDigit[target] == maxDigit[target - cost[i]] + 1)
            {
                target -= cost[i];
                ans += (char)('0' + (i+1));
            }
        }
        
        return ans;
        
    }
};