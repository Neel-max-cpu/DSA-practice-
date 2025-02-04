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
    ListNode *detectCycle(ListNode *head) {
        /*
        // int i =0;
        // unordered_map<ListNode*, int>m;
        unordered_set<ListNode*>m;
        ListNode *temp = head;
        while(temp!=NULL){
            if(m.find(temp) != m.end()){
                // if found
                return temp;
            }
            else{
                // if not found
                // m[temp] = i;
                // i++;
                m.insert(temp);
                temp = temp->next;
            }
        }
        return NULL;
        */

        if(head==NULL || head->next==NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *entry = head;        
        while(fast!= NULL && fast->next != NULL){
            // slow moves by 1 and fast by 2
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                // cycle detected
                while(slow!=entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};