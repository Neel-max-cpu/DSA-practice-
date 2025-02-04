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
#include<vector>
#include<algorithm>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // brute ---
        /*
        ListNode *temp = head;
        vector<int>v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        // reverse(v.begin(), v.end());
        ListNode *newHead = NULL;
        ListNode *tail = NULL;
        // for(int i=0; i<v.size(); i++){
        for(int i=v.size()-1; i>=0; i--){
            ListNode *newNode = new ListNode(v[i]);
            if(newHead == NULL){
                newHead = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }            
        }
        return newHead;
        */

        // better(best ---)
        // recursion --
        /*
        if(head==NULL || head->next==NULL) return head;

        ListNode *newhead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;

        return newhead;
        */

        // best ---
        // /*
        ListNode *current = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;

        while(current != NULL){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
          // */


    }
};