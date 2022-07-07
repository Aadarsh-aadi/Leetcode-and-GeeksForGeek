class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        //stack to store max values till now if we look from right
        stack<int> s;
        /*
            one way to think of circular array as two continous same array
            if we think so 
            the question simplifies
            all we need to find closer greater element from right
            so if current element is greater or equal than stack top then this would be a good        element as it is greater then previous few elements also have index small
            else we store the index greater and push the current to stack
        */
        
        int n = nums.size() , i , j;
        vector<int> ans(n);
        for(j = 1 ; j <=2 ; ++j)
        {
            for(i = n-1; i>=0 ; --i)
            {
                while(s.empty() == false && nums[s.top()] <= nums[i])
                {
                   
                    //cout << s.top() << "\t";
                    s.pop();
                }
                
                ans[i] = (s.empty() == false) ? nums[s.top()] : -1;
               
                s.push(i);
            }
        }
        
        return ans;
    }
};