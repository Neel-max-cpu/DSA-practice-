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
        ListNode *one = headA;        
        ListNode *two = headB;
        while(one && two){
            one = one->next;
            two = two->next;
        }
        if(one){
            int count = 0;            
            while(one){
                one = one->next;
                count++;
            }
            one = headA;
            for(int i=0; i<count; i++) one = one->next;
            two = headB;
        }
        else{
            int count = 0;
            while(two){
                count++;
                two = two->next;
            }
            two = headB;
            for(int i=0; i<count; i++) two = two->next;
            one = headA;
        }
        while(one!=two){
            one = one->next;
            two = two->next;
        }
        return one;
    }
};