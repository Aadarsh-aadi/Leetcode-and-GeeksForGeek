class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int mx = *max_element(candies.begin(),candies.end());
        int l = 1,r = mx;
        int maxCandies = 0;
        while(l <= r){
            int pileSize = l + (r - l) / 2;
            long long int piles = 0;
            for(int candy : candies){
               piles += candy / pileSize; 
            }
            if(piles >= k){
                maxCandies = pileSize;        
                l = pileSize + 1;
            } else {
                r = pileSize - 1;
            } 
        }
        return maxCandies;
    }
};