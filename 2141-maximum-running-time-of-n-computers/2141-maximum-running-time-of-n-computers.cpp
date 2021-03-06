class Solution {
public:
    bool isPossible(long long mid, vector<int>& batteries, int n){
         long long sum = 0;
         for(long long ele : batteries){
             if(ele >= mid) sum += mid;
             else sum += ele;
         }
        
         return sum / n >= mid;
    }
    
    
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        
          sort(batteries.rbegin(), batteries.rend());
          
          if(batteries.size() == 1) return batteries[0];
        
          long long lo = batteries[n - 1];
          long long hi =0;
          for(long long ele : batteries) hi = hi + (long long) ele;
         if(n == 1) return hi;
          hi = hi / n;
          long long ans = 0;
          while(lo <= hi){
              long long mid = lo + (hi - lo) / 2;
              if(isPossible(mid, batteries, n)){
                  ans = mid;
                  lo = mid + 1;
              }
              else hi = mid - 1;
          }
          return ans;
    }
};