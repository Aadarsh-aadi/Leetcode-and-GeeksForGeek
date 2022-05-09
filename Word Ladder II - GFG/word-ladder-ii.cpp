// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
 vector<vector<string>> result;
    
    void DFS(string beginWord, string endWord, unordered_map<string, set<string>> &adjList, vector<string> &path){
        path.push_back(beginWord);
        if(beginWord == endWord){
            result.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x: adjList[beginWord]){
            //cout << beginWord <<" "<<x << endl;
            DFS(x, endWord, adjList, path);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // Intution here
        /*
            Similar to Word Ladder I
            just need to store parent string 
        */
        // Code here
        unordered_map<string, set<string>> adjList;
        int i,level,n = wordList.size() , m = beginWord.size();
        
        if(beginWord == endWord)
        return {{beginWord}};
        
        //check if targetWord exist or not
        for(i=0;i<n;++i)
        {
            if(wordList[i] == endWord)
            {
                break;
            }
        }
        
        if(i == n)
        {
            return result;
        }
        
       
        //bfs
        level = 0;
        int sizeofQ,j,c=0 ,k;
        queue<string> q;
        
        // visited map
        unordered_map<string,int> mp;
        
        //initialize queue 
        q.push(beginWord);
        mp[beginWord] = 1;
        while(!q.empty())
        {
            sizeofQ = q.size();
            ++level;
            
            //level traversal
            for(i=0;i<sizeofQ;++i)
            {
                 string s = q.front();
                 q.pop();
               // cout << s << endl;
                 // finding next node
                 for(j=0;j<n;++j)
                 {
                     // same string or visited string
                     if(s == wordList[j])
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
                             if(mp.find(s1) == mp.end())
                             {
                                 mp[s1] = level+1;
                                 q.push(s1);
                                 adjList[s].insert(s1);
                             }
                             else if(mp[s1] == mp[s]+1)
                             {
                                  adjList[s].insert(s1);
                             }
                            
                         }
                     
                 }
                 
            }
        }
        
         vector<string> path;
        DFS(beginWord, endWord, adjList, path);
        
        return result;

    }
};

// { Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}  // } Driver Code Ends