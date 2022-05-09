class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        int i,level,n = wordList.size() , m = startWord.size();
     
        
        set<string> setS;
        //check if targetWord exist or not
        for(i=0;i<n;++i)
        {
            setS.insert(wordList[i]);
        }
        
        if(setS.find(targetWord) == setS.end())
        {
            return 0;
        }
        
        //cout << "bfs";
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
                
                string temp = s;
                 // finding next node
                for(j=0;j<m;++j)
                {
                    for(char ch = 'a';ch <= 'z';++ch,temp = s)
                    {
                        if(temp[j] == ch)
                            continue;
                        char c = temp[j];
                        temp[j] = ch;
                        //cout << temp <<" "<<j<<"\t";
                        if(temp == targetWord)
                            return level+1;
                        if(setS.find(temp) == setS.end())
                            continue;
                        if(mp.find(temp) == mp.end())
                        {
                           // cout <<" "<<temp;
                            q.push(temp);
                            mp[temp] = 1;
                        }
                        
                       
                    }
                }
                     
                 
                 
            }
        }
        
        // if target is present but unattainable
        return 0;
    }
};