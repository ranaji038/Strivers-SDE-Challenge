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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    if(list1 == NULL) return list2;
    else if(list2 == NULL) return list1;

    if(list1->val > list2->val){
        ListNode * newhead = list2;
        ListNode * tail = mergeTwoLists(list1,list2->next);
    newhead->next = tail ;
    return newhead;
    }else {

ListNode* newhead = list1;
        ListNode * tail = mergeTwoLists(list1->next,list2);
    newhead->next = tail ;
    return newhead;
    }
    }
};