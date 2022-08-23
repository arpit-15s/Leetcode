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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;
        stack<int> s;
        ListNode* mid = head;
        bool even = false;
        while(head != NULL && head -> next != NULL){
            s.push(mid -> val);
            mid = mid -> next;
            head = head -> next -> next;
            if(head == NULL) even = true;
        }
        if(!even)
            mid = mid -> next;
        cout << s.size() << endl;
        while(!s.empty()){
            if(s.top() != mid -> val)
                return false;
            s.pop();
            mid = mid -> next;
        }
        return true;
    }
};