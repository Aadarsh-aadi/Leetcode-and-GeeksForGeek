class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        
        long long int sum = 0 , i , n = nums.size() , c , mod = 1e9+7 , j , index;
        long long int ans = 0LL;
        vector<long long int> left(n),right(n);
        stack<long long int> s;
       
        for(i = n-1 ; i>=0 ; --i)
        {
            //cout << i << "\\\\\   ";
            while(s.empty() == false && nums[i] <= nums[s.top()])
            {
                index = s.top();
                j = s.top() - i - 1;
                right[index] = j ;
                s.pop();
            }
            cout <<"\n ttttt   ";
            j = (s.empty() == true) ? n : s.top();
            j = j - i - 1;
            
            left[i] = j;
            s.push(i);
        }
        i = 0;
        cout << endl << endl;
        while(s.empty() == false)
        {
           // cout << s.top() << endl;
            j =  s.top() - i ;
            index = s.top() ;
            right[index] = j ;
            s.pop();
        }
        
        for(i = 0 ; i < n ; ++i)
        {
            index = i ;
            j = ((left[i]+1)%mod)*((right[i]+1)%mod);
            ans = (ans%mod +(j%mod * nums[index]%mod)%mod);
        }
        return ans;
    }
};