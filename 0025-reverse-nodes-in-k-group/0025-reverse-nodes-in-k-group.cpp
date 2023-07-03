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
        
 ListNode * dotheneedfull(ListNode* head, int k , int len){
          if(head == NULL || k == 1 || len < k) return head;
            
            ListNode * next = NULL , *prev = NULL , *curr = head;
            int cnt = 0;
            while(curr != NULL && cnt <k){
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    cnt++;
            }
            
            if(next != NULL) head->next = dotheneedfull(next,k , len - k);
            return prev;
            
 }
        
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
           int len = 0;
            ListNode * temp = head;
            while(temp != NULL){
                    temp = temp->next;
                    len++;
            }
            cout<<"length is : "<<len;
            return dotheneedfull(head, k , len);
    }
};