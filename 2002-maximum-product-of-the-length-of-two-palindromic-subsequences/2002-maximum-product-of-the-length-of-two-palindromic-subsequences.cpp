class Solution {
public:
    int ans=0;
    bool isPal(string& s)
    {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string& s,string& s1,string& s2,int i)
    {
        if(i>=s.size())
        {
            if(isPal(s1)&&isPal(s2))
            {
                ans=max(ans,(int)(s1.size())*(int)(s2.size()));
                
            }
            return;
        }
        
        s1+=s[i];
        helper(s,s1,s2,i+1);
        s1.pop_back();
        
        s2+=s[i];
        helper(s,s1,s2,i+1);
        s2.pop_back();
        
        helper(s,s1,s2,i+1);
    }
    int maxProduct(string s) 
    {
        string s1="",s2="";
        int i=0;
        helper(s,s1,s2,i);
        return ans;
    }
};