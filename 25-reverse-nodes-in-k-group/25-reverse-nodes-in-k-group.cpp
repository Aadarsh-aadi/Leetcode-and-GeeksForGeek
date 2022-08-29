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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        int count = 0;
        ListNode* tail ;
        ListNode* prevTail;
        ListNode* prev = NULL;
        ListNode* root = new ListNode(0) ;
        ListNode* curr = head;
        ListNode* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        //cout << curr->next << endl;
        
        int n , i = count%k ;
        prevTail = root;
        temp = curr;
        while(count >= k)
        {
            //cout << count << endl;
            n = 0;
            prev = NULL;
            tail = curr ; // constant for every iterations
            while(n < k)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp; 
                n++;
            }
            
            /* Dont touch curr and temp they should be persisted between two while iterations*/
            prevTail->next = prev ;
           // cout << prev->val << " " << tail->val << endl;
            prevTail = tail ;
            count -= k;
        }
        
        if(i)
            prevTail->next = curr;
        return root->next;
    }
};