/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)
            return head;
        Node* root = new Node();
        Node* itr = root;
        stack<Node*> st;
        st.push(head);
        
        while(st.empty() == false)
        {
            Node* topNode = st.top();
            st.pop();
            if(topNode->next != NULL)
            {
                st.push(topNode->next);
            }
             if(topNode->child != NULL)
            {
                st.push(topNode->child);
            }
            
            itr->next = topNode;
            topNode->prev = itr;
            itr = itr->next;
            itr->child = NULL;
        }
        
        root = root->next;
        root->prev = NULL;
        
        return root;
    }
};