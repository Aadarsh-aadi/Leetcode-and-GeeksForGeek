class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int i,n = s.size(),mx = 0;
        
        stack<int> stk;
        //base index to start new valid substring
        stk.push(-1);
        
        for(i=0;i<n;++i)
        {
            if(s[i] == '(')
            stk.push(i);
            else{
                if(stk.empty() == false)
                {
                    stk.pop();
                }
                
                if(stk.empty() == false)
                {
                    mx = max(mx,i - stk.top());
                }
                else
                {
                    stk.push(i);
                }
            }
        }
        
        return mx;   
    }
};