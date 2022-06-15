class Solution {
public:
    bool isPossible(vector<int> weights,int val,int days,int n)
    {
        int c=1,s=0,i;
        for(i=0;i<n;++i)
        {
            if(weights[i] > val)
                return false;
            if(weights[i]+s > val)
            {
                c++;
                if(c > days)
                    return false;
                s = weights[i];
            }
            else
                s+=weights[i];
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int i,sum=0,n=weights.size();
        for(i=0;i<n;++i)
        {
            sum+= weights[i];
        }
        
        int l=0,r=sum,mid,ans=0;
        
        while(l<=r)
        {
           
            mid = l + (r-l)/2;
             //cout << l<<" "<<mid<<" "<<r <<endl;
            if(isPossible(weights,mid,days,n) == true)
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