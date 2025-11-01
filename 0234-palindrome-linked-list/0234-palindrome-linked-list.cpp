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
    ListNode*doReverse(ListNode*head){
        ListNode*prev = NULL;
        ListNode*curr = head;
        while(curr!=NULL){
            ListNode*next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool check(ListNode*head1, ListNode*head2){
        while(head1 && head2){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return false;
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow will point to first one
        prev->next = NULL;        
        ListNode* next = doReverse(slow);        

        return check(head, next);
    }
};