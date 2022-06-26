class Solution {
public:
    int largestCombination(vector<int>& arr) 
    {
        int mx = 0, i , n = arr.size() , bit=0;
        
        for(i=0;i<n;++i)
        {
            mx = max(mx,arr[i]);
        }
        
       int temp = 1<<bit;
        while(mx >= temp)
        {
            bit++;
            temp = 1<<bit;
        }
        
        int cmx = 0,j,k;
        
        for(i=0;i<bit;++i)
        {
            mx=0;
            j = 1<<i;
            for(k=0;k<n;++k)
            {
                if(arr[k]&j)
                {
                    mx++;
                }
                    
            }
            cmx = max(mx,cmx);
        }
        
        return cmx;
        
    }
};