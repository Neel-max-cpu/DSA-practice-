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
        ListNode*curr = head;
        int len = 0;
        while(curr){
            curr = curr->next;
            len++;
        }
        int toRemove = len-n+1;
        if(toRemove == 1) return head->next;
        ListNode*prev = NULL;
        curr = head;
        while(curr){
            toRemove--;
            if(toRemove==0){
                ListNode*next = curr->next;
                prev->next = next;
                curr->next = NULL;
                delete(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;

    }
};