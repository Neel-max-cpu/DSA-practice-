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
    pair<ListNode*,ListNode*> doReverse(ListNode*start){
        ListNode*temp = start;
        ListNode *prev = NULL;
        while(temp!=NULL){
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        // prev will be head and start will be tail
        return {prev, start};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *start = head;
        ListNode*prevTail = NULL;
        int count = 0;
        ListNode*newHead = NULL;
        bool isFirst = true;
        while(curr!=NULL){
            count++;
            if(count==k){
                count = 0;
                ListNode *nextNode = curr->next;
                curr->next = NULL;
                auto p = doReverse(start);
                if(isFirst){
                    newHead = p.first;
                    isFirst = false;
                }             
                else{
                    prevTail->next = p.first;
                }                 
                p.second->next = nextNode;     
                start = nextNode;   
                prevTail = p.second;
                curr = p.second;                        
            }
            prev = curr;
            curr = curr->next;
        }
        return newHead;
    }
};