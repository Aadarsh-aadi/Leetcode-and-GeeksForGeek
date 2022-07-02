class TrieNode{
    public:
        TrieNode* children[26];
        string word;
        TrieNode(){
            word = "";
            for(int i=0 ; i<26 ; ++i)
            {
                children[i] = NULL;
            }
        }
    
        bool isPresent(char c)
        {
            return (children[c-'a'] == NULL) ? false : true ;
        }
        
        void put(char c , TrieNode* node)
        {
            children[c-'a'] = node;
        }
    
        TrieNode* getNode(char c)
        {
            return children[c-'a'];
        }
    
};

class Solution {
public:
    TrieNode* buildTree(vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        for(int i = 0 ; i < words.size() ; ++i)
        {
            TrieNode* curr = root;
            string s = words[i];
            for(int j = 0 ; j < words[i].size() ; ++j)
            {
                if(curr->isPresent(words[i][j]) == false)
                {
                    curr->put(words[i][j] , new TrieNode());
                }
                 
                curr = curr->getNode(words[i][j]);
            }
            curr->word = s;
        }
        
        return root;
    }
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) return;
        p = p->children[c - 'a'];
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        TrieNode* root = buildTree(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
        
    }
};