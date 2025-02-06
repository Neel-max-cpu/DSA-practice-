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
        ListNode *fast = head;
        ListNode *slow = head;
        vector<int>v;
        ListNode *temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        ListNode *newhead = new ListNode();
        temp = newhead;
        for(int i=0;i<v.size(); i++){
            if(i==v.size()/2) continue;
            else{
                ListNode *newnode = new ListNode(v[i]);
                temp->next = newnode;
                temp = temp->next;
            }
        }
        return newhead->next;
    }
};