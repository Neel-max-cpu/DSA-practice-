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
    ListNode *reverseLink(ListNode *head){
        ListNode *curr = head;
        ListNode *nex = NULL;
        ListNode *prev = NULL;
        while(curr!=NULL){
            nex = curr->next;
            curr->next = prev;
            prev=curr;
            curr = nex;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        // brute
        /*
        ListNode *temp = head;
        vector<int>v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        for(int i=0; i<v.size()/2; i++){
            if(v[i]!=v[v.size()-i-1]){
                return false;
            }
        }
        return true;
        */

        // optimal 
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            // here not fast!=null and fast->next != null
            // as even len has 2 middle, so we need the first middle -- so fast will stand at the 2nd last ele
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseLink(slow->next);
        slow = slow->next;
        while(slow!=NULL){
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};