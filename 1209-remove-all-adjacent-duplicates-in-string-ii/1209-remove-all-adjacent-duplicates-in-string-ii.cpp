class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> stk;
        int i,n=s.size(),j;
        char ch;
        stk.push({s[0],1});
        for(i=1;i<n;++i)
        {
            
            if(stk.empty()==false && stk.top().first == s[i])
            {
                if(stk.top().second + 1 < k)
                {
                    j = stk.top().second + 1;
                    stk.pop();
                    stk.push({s[i],j});
                }
                else
                stk.pop();
            }
            else
            {
                stk.push({s[i],1});
            }
        }
         string res;
        while(!stk.empty())
        {
            j=stk.top().second;
            ch = stk.top().first;
        while(j--)
            res.push_back(ch);
        stk.pop();
     }
    
    reverse(res.begin(), res.end());
    return res;
    }
};