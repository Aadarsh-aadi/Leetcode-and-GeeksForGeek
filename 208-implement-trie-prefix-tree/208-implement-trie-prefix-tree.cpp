class Node{
    public : 
        Node* links[26];
        bool isEndOfTheWord;
        Node()
        {
           for(int i=0;i<26;++i)
           {
               links[i] = NULL;
           }
            isEndOfTheWord = false;
         }
        
        bool containKey(char ch)
        {
            return (links[ch-'a']==NULL)? false : true ;
        }
        
        void put(char ch,Node* node)
        {
            links[ch-'a'] = node;
        }
    
        Node* getNode(char ch)
        {
            return links[ch-'a'];
        }
    
        void setEnd()
        {
            isEndOfTheWord = true;
        }
        
        bool getEnd()
        {
            return isEndOfTheWord;
        }
};


class Trie {
public:
    Node* root;
    Trie() 
    {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node* node = root;
        for(int i=0;i<word.length();++i)
        {
            if(node->containKey(word[i]) == false)
            {
                node->put(word[i],new Node());
            }
            
            node = node->getNode(word[i]);
        }
        
        node->setEnd();
        
    }
    
    bool search(string word) 
    {
         Node* node = root;
        for(int i=0;i<word.length();++i)
        {
            if(node->containKey(word[i]) == false)
            {
               return false;
            }
            
            node = node->getNode(word[i]);
        }
        
        return node->getEnd();
    }
    
    bool startsWith(string word) 
    {
        Node* node = root;
        for(int i=0;i<word.length();++i)
        {
            if(node->containKey(word[i]) == false)
            {
               return false;
            }
            
            node = node->getNode(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */