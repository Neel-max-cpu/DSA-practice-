/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA;
        ListNode *second = headB;
        int lenFirst = 0, lenSecond = 0;
        while(first!=NULL){
            lenFirst++;
            first = first->next;
        }
        while(second!=NULL){
            lenSecond++;
            second = second->next;
        }
        first = headA; second = headB;
        if(lenFirst>lenSecond){
            for(int i=0; i<lenFirst-lenSecond; i++) first = first->next;
        }
        else{
            for(int i=0; i<lenSecond-lenFirst; i++) second = second->next;
        }

        while(first!=second){
            first = first->next;
            second = second->next;
        }
        return first;
    }
};