class Solution {
public:
    int bs(int mid , vector<int>& houses, vector<int>& heaters)
    {
        int n = houses.size() , m = heaters.size() , i = 0 , j = 0;
        
        while(i < n && j < m)
        {
            if(abs(houses[i] - heaters[j]) <= mid)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        return (i==n) ? true : false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        int l = 0 , r = 1e9 , mid , ans;
        sort(houses.begin() , houses.end());
        sort(heaters.begin() , heaters.end());
        
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(bs(mid,houses,heaters) == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};