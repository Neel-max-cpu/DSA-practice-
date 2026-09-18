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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*newNode = new ListNode(-1);
        ListNode*curr = newNode;

        while(list1 || list2){
            if(list1 && list2){
                // both are there then
                ListNode*temp = NULL;
                if(list1->val <= list2->val){
                    temp = new ListNode(list1->val);                    
                    list1 = list1->next;
                }
                else{
                    temp = new ListNode(list2->val);
                    list2 = list2->next;
                }
                curr->next = temp;
                curr = curr->next;
            }
            else if(list1){
                curr->next = list1;
                break;
            }
            else{
                curr->next = list2;
                break;
            }
        }
        return newNode->next;
    }
};