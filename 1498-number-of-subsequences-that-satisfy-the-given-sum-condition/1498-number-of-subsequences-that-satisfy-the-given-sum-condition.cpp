class Solution {
public:
    inline int add(int a,int b,int mod){
        return (int)((1LL*a%mod + b%mod)%mod);
    }
    
    int bin(int a,int b,int mod){
        int res=1;
        while(b){
            if(b&1){
                res=(res%mod * 1LL*a%mod)%mod;
            }
            b>>=1;
            a=(a%mod * 1LL*a%mod)%mod;
        }
        res--; //-1 for excluding empty subset
        return res%mod;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int sz=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<sz;i++){
            int val=nums[i];
            if(val*2 <=target){
                cnt=add(cnt,1,mod);
            }
            int elems=upper_bound(nums.begin()+i+1,nums.end(),target-val)-(nums.begin()+i+1);
            cnt=add(cnt,bin(2,elems,mod),mod); 
        }
        return cnt;
    }
};