class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int n = heights.size() , i = 0 , mxAns = 0 ;
        stack<int> s;
        
        // 2 2 4
        
        while(i < n)
        {
            if(s.empty() == true || heights[s.top()] <= heights[i])
                s.push(i++);
            else
            {
                int tpIndex = s.top();
                s.pop();
                int width = (s.empty() == true) ? i : (i - s.top() - 1);
                int area = heights[tpIndex] * width;
                mxAns = max(mxAns , area);
            }
        }
        
        while(s.empty() == false)
        {
               int tpIndex = s.top();
                s.pop();
                int width = (s.empty() == true) ? i : (i - s.top() - 1);
                int area = heights[tpIndex] * width;
                mxAns = max(mxAns , area);
        }
        
        return mxAns;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        // construct height array
        
        int rows = matrix.size() , cols = matrix[0].size();
        
        vector<int> height(cols,0);
        
        int r , c , ans = 0 , mxAreaRow;
        //first initial height
        
       
        
        for(r = 0 ; r < rows ; ++r)
        {
            for( c = 0 ; c < cols ; ++c)
            {
                if(matrix[r][c] == '1')
                    height[c]++;
                else
                    height[c] = 0;
            }
            mxAreaRow = maxArea(height);
            ans = max(ans,mxAreaRow);
        }
        
        return ans;
        
    }
};