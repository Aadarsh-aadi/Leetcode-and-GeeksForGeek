class Solution {
public:
    bool bs(vector<int> q ,int val,int n,int k)
    {
        int i,c=0;
        for(i=0;i<n;++i)
        {
            c += (q[i]/val);
            if(q[i]%val)
                c++;
            if(c > k)
                return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int i=0,r=INT_MAX,q=quantities.size();
        
        for(i=0;i<q;++i)
        {
            r = max(r,quantities[i]);
        }
        int l=1,mid,ans=r;
        
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(bs(quantities,mid,q,n) == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid+1;
            
        }
        
        return ans;
        
    }
};