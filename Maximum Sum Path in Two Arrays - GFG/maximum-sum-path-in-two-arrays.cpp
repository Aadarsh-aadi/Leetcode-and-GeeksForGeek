// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// This function returns the sum of elements on maximum path
	// from beginning to end
	int maxPathSum(int nums1[], int nums2[], int len1, int len2) {
	    // code here
	    int ptr1=0 , ptr2=0 ;
        unsigned long long int s1 = 0 , s2 = 0 , ans = 0 ;
        long long int mod = 1e9+7;
        
        while(ptr1 < len1 && ptr2 < len2)
        {
            if(nums1[ptr1] < nums2[ptr2])
            {
                s1 += nums1[ptr1];
                s1 %= mod;
                ptr1++;
            }
            else if(nums1[ptr1] > nums2[ptr2])
            {
                s2 += nums2[ptr2];
                s2 %= mod;
                ptr2++;
            }
            else
            {
                s1 += nums1[ptr1];
                s1 %= mod;
                s2 += nums2[ptr2];
                s2 %= mod;
                ans += max(s1,s2);
                ans %= mod;
                s1 = 0;
                s2 = 0;
                ptr1++;
                ptr2++;
            }
        }
        
        while(ptr1 < len1)
        {
            s1 += nums1[ptr1];
            s1 %= mod;
            ptr1++;
        }
        
        while(ptr2 < len2)
        {
            s2 += nums2[ptr2];
            s2 %= mod;
            ptr2++;
        }
        
        ans += max(s1,s2);
        ans %= mod;
        return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maxPathSum(arr1, arr2, m, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends