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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;

        // brute 
        /*
        vector<int>v;
        ListNode *temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        

        ListNode *newhead = new ListNode(v[0]); 
        temp = newhead;
        for(int i=2; i<v.size(); i+=2){
            ListNode *newnode = new ListNode(v[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        for(int i=1; i<v.size(); i+=2){
            ListNode *newnode = new ListNode(v[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        return newhead;
        */ 

        // best --
        ListNode *odd = head;
        ListNode* even = head->next;
        ListNode *evenhead = even;

        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
       
    }
};