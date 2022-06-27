class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) 
    {
    long long int a=0,b=0;
    long long int ans =0;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    while(i<n and j<m){
        if(nums1[i] < nums2[j]){
            a+=nums1[i];
            i++;
        }
        else if(nums1[i] > nums2[j]){
            b+=nums2[j];
            j++;
        }
        else{
            ans = ans+ max(a,b) + nums1[i];
            a=0,b=0;i++;j++;
        }
    }
    while(i<n) a+=nums1[i++];
    while(j<m) b+=nums2[j++];
    ans+= max(a,b);
    ans%=1000000007;
    return ans;
    }
};