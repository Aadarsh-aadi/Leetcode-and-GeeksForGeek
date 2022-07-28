class Solution {
public:
    int merge(vector<int>& arr , int left , int mid , int right)
    {
        // first count number of pairs
        // then sort the list for further process
            int i = left,j = mid+1;
            int c = 0;
            vector<int> temp;
                //first count
                while(i <= mid && j <= right)
                {
                    if((long long)arr[i] > (long long) 2*arr[j])
                    {
                        c += mid-i+1;
                        j++;
                    }
                    else
                        i++;
                }

            i = left;
            j = mid + 1;
                // sorting
            while(i <= mid && j<=right)
            {
                if(arr[i] <= arr[j]){
                   temp.push_back(arr[i]);
                   i++;
                }
                else{
                    temp.push_back(arr[j]);
                    j++;
                }
            }

            while(i <= mid)
            {
                temp.push_back(arr[i]);
                   i++;
            }
            while(j<=right)
            {
                 temp.push_back(arr[j]);
                    j++;
            }

            j=0;
            
            for(i=left;i<=right;++i){
            
            arr[i] = temp[j++];
            }
           
            return c;
    }
    int mergesort(vector<int>& nums , int start , int end)
    {
        if(start < end)
        {
            int x , y , z , mid;
            mid = start + (end-start)/2;
            
            x = mergesort(nums,start,mid);
            y = mergesort(nums,mid+1,end);
            z = merge(nums,start,mid,end);
            
            return x+y+z;
        }
        
        return 0;
    }
    int reversePairs(vector<int>& nums) 
    {
        return mergesort(nums,0,nums.size() - 1);
    }
};