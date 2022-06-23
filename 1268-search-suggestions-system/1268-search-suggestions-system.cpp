class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
       int i,n = searchWord.size(),start = 0,end ;
       sort(products.begin(), products.end());
       vector<vector<string>> result(n);
        end = products.size()-1;
        
        for(i=0;i<n;++i)
        {
            while(start <= end &&
                  (products[start].size() <= i || products[start][i] != searchWord[i]))
            {
                ++start;
            }
            while(start <= end &&
                  (products[end].size() <= i || products[end][i] != searchWord[i]))
            {
                --end;
            }
            int k = min(start+2,end);
            for(int j = start ; j<=k; ++j)
            {
                result[i].push_back(products[j]);
            }
        }
        
        return result;
    }
};