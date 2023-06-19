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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          
        ListNode * newhead = new ListNode();
            newhead->next = head;
            
            ListNode*fast = newhead;
            ListNode * slow = newhead;
            while(n--) fast = fast->next;
            
            while(fast != NULL && fast->next != NULL){
                    slow = slow->next;
                    fast = fast->next;
                    
            }
            slow->next = slow->next->next;
            return newhead->next;
            
            
            
    }
};