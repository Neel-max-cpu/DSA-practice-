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
        if(head==NULL) return NULL;

        /*
        int count = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }

        //since from the last so nth node will be first
        if(count==n){
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        int res = count - n;
        temp = head;
        while(temp!=NULL){
            res--;
            if(res==0) break;
            temp = temp->next;
        }
        
        ListNode *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
        */

        //better way --
        /*
        The dummy node is a "helper node" placed before the head:
        Reason:
        Edge cases: If we need to remove the first node (n = length of list),
        there is no previous node to update next.
        With dummy, the node before the one to delete is always accessible (slow will point to it).
        It makes the code uniform — we don’t need separate logic for deleting the head.
        */
        ListNode *dummy = new ListNode(0,head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        //move n+1 
        /*
        Why move fast n+1 steps ahead?
        fast starts at dummy.
        slow starts at dummy.
        Moving fast n+1 steps ensures that the distance between slow and fast is n+1 nodes.
        Key idea:
        When fast reaches the end (NULL), slow is exactly one node before the node to delete.
        This works because the gap ensures slow->next is the nth node from the end.
        */
        for(int i=0; i<=n; i++){
            fast = fast->next;
        }
        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;            
        }
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return dummy->next;
    }
};