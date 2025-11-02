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
    int countLen(ListNode*head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode*getPrevVal(ListNode*head, int n){
        for(int i=0; i<n-1; i++){
            head = head->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(n==1 && head->next==NULL) return head->next;
        int len = countLen(head);   
        int k = len-n;        
        if(k==0) return head->next;
        ListNode*prevVal = getPrevVal(head, k);        
        ListNode *delNode = prevVal->next;
        prevVal->next = delNode->next;        
        delete delNode;
        return head;        
    }
};