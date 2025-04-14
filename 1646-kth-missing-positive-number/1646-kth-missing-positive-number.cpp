class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size() , i , j = 0 , last = 0, num;
        for (i = 0 ; i < n ; ++i){
            num = arr[i] - last - 1;
            if(num + j >= k){
                return last + k - j ;
            }
            j = num + j ;
            last = arr[i];
        }

        return arr[n-1] + k - j;
    }
};