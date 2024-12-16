/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextPtr = (node->next)->next;
        node->val = (node->next)->val;
        (node->next)->next = NULL;
        node->next = nextPtr;
    }
};