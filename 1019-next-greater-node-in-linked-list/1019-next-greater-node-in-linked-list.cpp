/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    stack<int> s;
    void recur(ListNode* node)
    {
        if(node->next == NULL)
        {
            s.push(node->val);
            ans.push_back(0);
            return;
        }
        
        recur(node->next);
        while(s.empty() == false && s.top() <= node->val)
            s.pop();
        int c = (s.empty() == false) ? s.top() : 0 ;
        ans.push_back(c);
        s.push(node->val);
        return;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        recur(head);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};