class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> stk;
        int i,n=s.size();
        stk.push(s[0]);
        for(i=1;i<n;++i)
        {
            
            if(stk.empty()==false && stk.top() == s[i])
            {
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
         string res;
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    
    reverse(res.begin(), res.end());
    return res;
    }
};