class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k)
            return k;
        int n = arr.size() ;
        int l = 0 , r = n-1 , mid, mis;

        while(l <= r) {
            mid = l + (r - l)/2;
            mis = arr[mid] - mid - 1;
            if(mis >= k)    
                r = mid - 1;
            else
                l = mid + 1;
        }
       return k + r + 1;
    }
};