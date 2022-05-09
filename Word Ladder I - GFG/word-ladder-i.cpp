// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int i,level,n = wordList.size() , m = startWord.size();
        
        if(startWord == targetWord)
        return 1;
        
        //check if targetWord exist or not
        for(i=0;i<n;++i)
        {
            if(wordList[i] == targetWord)
            {
                break;
            }
        }
        
        if(i == n)
        {
            return 0;
        }
        
        //bfs
        level = 0;
        int sizeofQ,j,c=0 ,k;
        queue<string> q;
        
        // visited map
        unordered_map<string,int> mp;
        
        //initialize queue 
        q.push(startWord);
        
        while(!q.empty())
        {
            sizeofQ = q.size();
            ++level;
            
            //level traversal
            for(i=0;i<sizeofQ;++i)
            {
                 string s = q.front();
                 q.pop();
                 mp[s] = 1;
                 // finding next node
                 for(j=0;j<n;++j)
                 {
                     // same string
                     if(mp.find(wordList[j]) != mp.end())
                     continue;
                    
                         c = 0;
                         string s1 = wordList[j];
                         
                         // find number of different characters
                         for(k=0;k<m;++k)
                         {
                             if(s[k] != s1[k])
                             {
                                 c++;
                                if(c==2)
                                break;
                             }
                         }
                         
                         // if count is equal to 1 then it is next node
                         if(c == 1)
                         {
                             // if target is found
                             if(s1 == targetWord)
                             {
                                 return level+1;
                             }
                             //node push
                             q.push(s1);
                         }
                     
                 }
                 
            }
        }
        
        // if target is present but unattainable
        return 0;

    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends