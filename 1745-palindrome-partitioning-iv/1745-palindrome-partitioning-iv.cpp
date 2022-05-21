class Solution {
public:
    bool checkPartitioning(string str) {
       
        int i,j,k,L,n = str.size();
        bool P[n][n];
    // Every substring of length 1 is a palindrome
    for (i = 0; i < n; i++) 
    {
        P[i][i] = true;
    }
 
    /* L is substring length. Build the solution in bottom up manner by
       considering all substrings of length starting from 2 to n. */
    for (L = 2; L <= n; L++) 
    {
        // For substring of length L, set different possible starting indexes
        for (i = 0; i < n - L + 1; i++) 
        {
            j = i + L - 1; // Set ending index
 
            // If L is 2, then we just need to compare two characters. Else
            // need to check two corner characters and value of P[i+1][j-1]
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
        }
    }
        for(i=1;i<n-1;++i)
        {
            for(j=0;j<i;++j)
            {
                if(P[0][j] && P[j+1][i] && P[i+1][n-1])
                    return true;
            }
        }
        
        return false;
    }
};