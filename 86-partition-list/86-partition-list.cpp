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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* greater = new ListNode(0);
        ListNode *curr = head, *lCurr = less, *gCurr = greater;
        while(curr != NULL){
            if(curr -> val < x){
                lCurr -> next = curr;
                lCurr = lCurr -> next; 
            }
            else{
                gCurr -> next = curr;
                gCurr = gCurr -> next; 
            }
            curr = curr -> next;
            lCurr -> next = NULL;
            gCurr -> next = NULL;
        }
        lCurr -> next = greater -> next;
        return less -> next;
    }
};