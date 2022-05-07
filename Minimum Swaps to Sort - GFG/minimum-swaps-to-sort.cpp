// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    map<int,int> mp;
	    vector<int>temp = nums;
	    int i , n = nums.size(),ans=0;
	    for(i=0;i<n;++i)
	    {
	        mp[nums[i]] = i;
	    }
	    sort(nums.begin(),nums.end());
	    
	    for(i=0;i<n;++i)
	    {
	        if(mp[nums[i]] == i)
	        continue;
	        else
	        {
	            ans++;
	           
	            int j = temp[i],index = mp[nums[i]];
	            temp[i] = nums[i];
	            temp[index] = j;
	             
	            mp[j] = index;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends