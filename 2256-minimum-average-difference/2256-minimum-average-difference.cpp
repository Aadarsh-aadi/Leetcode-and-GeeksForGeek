class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
           int n=nums.size();
        vector<long long>back(n);
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            back[i]=sum;
        }
        
        int ans=INT_MAX;
        long long lsum=0;
        int index;
        for(int i=0;i<n;i++){
            lsum+=nums[i];
            if(i==n-1){
                int lavg=lsum/(i+1);
                if(ans>lavg){
                    ans=lavg;
                    index=i;
                }
                 
            }
            else
            {
                int lavg=lsum/(i+1);
                int ravg=back[i+1]/(n-i-1);
                int diff=abs(lavg-ravg);
               if(ans>diff){
                    ans=diff;
                    index=i;
                }
            }
        }
        
        return index;
    }
};