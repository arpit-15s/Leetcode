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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry = 0;
        while(curr1 != NULL && curr2 != NULL){
            curr -> val = (curr1 -> val + curr2 -> val + carry) % 10;
            carry = (curr1 -> val + curr2 -> val + carry) / 10;
            if(carry != 0 || curr1 -> next != NULL || curr2 -> next != NULL){
                curr -> next = new ListNode(0);
                curr = curr -> next;
            }
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        
        while(curr1 != NULL){
            curr -> val = (curr1 -> val + carry) % 10;
            carry = (curr1 -> val + carry) / 10;
            if(carry != 0 || curr1 -> next != NULL){
                curr -> next = new ListNode(0);
                curr = curr -> next;
            }
            curr1 = curr1 -> next;
        }
        
        while(curr2 != NULL){
            curr -> val = (curr2 -> val + carry) % 10;
            carry = (curr2 -> val + carry) / 10;
            if(carry != 0 || curr2 -> next != NULL){
                curr -> next = new ListNode(0);
                curr = curr -> next;
            }
            curr2 = curr2 -> next;
        }
        curr -> val += carry;
        
        return res;
    }
};