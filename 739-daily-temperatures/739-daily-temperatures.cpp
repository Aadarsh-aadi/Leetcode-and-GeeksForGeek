class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        stack<int> s;
        int i , n = temp.size();
        vector<int> ans(n);
        for(i = n-1 ; i >= 0 ; --i)
        {
            while(s.empty() == false && temp[s.top()] <= temp[i])
                s.pop();
            ans[i] = (s.empty() == 0) ? s.top() - i : 0 ;
            s.push(i);
        }
        
        return ans;
    }
};