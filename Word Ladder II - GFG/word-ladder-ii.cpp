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
            DFS(x, endWord, adjList, path);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, set<string>> adjList;
        set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> queue;
        queue.push(beginWord);
        unordered_map<string, int> isVisited;
        isVisited[beginWord] = 1;
        while(!queue.empty()){
            string currWord = queue.front();
            queue.pop();
            string tempWord = currWord;
            for(int i = 0; i < currWord.length(); i++){
                for(char x = 'a'; x <= 'z'; x++){
                    if(tempWord[i] == x)
                        continue;
                    tempWord[i] = x;
                    if(dict.count(tempWord) > 0){
                        if(isVisited.count(tempWord) == 0){
                            isVisited[tempWord] = isVisited[currWord]+1;
                            queue.push(tempWord);
                            adjList[currWord].insert(tempWord);
                        }
                        else if(isVisited[tempWord] == isVisited[currWord] + 1){
                            adjList[currWord].insert(tempWord);
                        }
                    }
                }
                tempWord[i] = currWord[i];
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