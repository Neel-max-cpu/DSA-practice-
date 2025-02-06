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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        // brute ---
        /*
        vector<int>v;
        ListNode *temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        ListNode *newhead = new ListNode(v[0]);
        temp = newhead;
        for(int i=1;i<v.size(); i++){
            if(i==v.size()/2) continue;
            else{
                ListNode *newnode = new ListNode(v[i]);
                temp->next = newnode;
                temp = temp->next;
            }
        }
        return newhead;
        */

        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next->next!=NULL && fast->next->next->next!=NULL){
            // fast->next->next -- even
            // fast->next->next->next -- odd
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *next = slow->next;
        slow->next = next->next;
        next->next = NULL;
        delete next;
        return head;
    }
};