class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int i,n=rocks.size(),ans=0;
        map<int,int> mp;
        
        for(i=0;i<n;++i)
        {
            mp[capacity[i] - rocks[i]]++;
        }
        
        for(auto m : mp)
        {
            if(m.first*m.second <= additionalRocks)
            {
                ans+=m.second;
                additionalRocks -= m.first*m.second;
            }
            else
            {
                ans+=(additionalRocks/m.first);
                break;
            }
        }
        
        return ans;
    }
};