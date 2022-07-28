class Solution {
public:
    vector<int> ans;
    void merge(vector<pair<int,int>>& nums, int start , int mid , int end)
    {
        int p1 = start , p2 = mid + 1 , c = 0 , index , i , j;
        vector<pair<int,int>> temp;
        while(p1 <= mid && p2 <= end)
        {
            if(nums[p1].first > nums[p2].first)
            {
                c++;
                temp.push_back(nums[p2]);
                p2++;
            }
            else{
                index = nums[p1].second;
                ans[index] += c;
                temp.push_back(nums[p1]);
                p1++;
            }  
        }
        
        while(p1 <= mid)
        {
            index = nums[p1].second;
            ans[index] += c;
            temp.push_back(nums[p1]);
            p1++;
        }
        
        while(p2 <= end)
        {
            temp.push_back(nums[p2]);
             p2++;
        }
        
        for(i = start , j = 0 ; i <= end ; ++i , ++j)
        {
            nums[i] = temp[j];
        }
        
        return ;
    }
    void mergesort(vector<pair<int,int>>& nums, int start , int end)
    {
        if(start < end)
        {
            int mid = start + (end - start)/2;
            mergesort(nums,start,mid);
            mergesort(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int start = 0 , end = nums.size() - 1;
        ans = vector<int>(end+1,0);
        vector<pair<int,int>> num(end+1);
        
        for(int i = 0 ; i <= end ; ++i)
        {
            num[i] = make_pair(nums[i],i);
           // cout << num[i].first << " " << num[i].second << endl;
        }
        mergesort(num,0,end);
        return ans;
    }
};