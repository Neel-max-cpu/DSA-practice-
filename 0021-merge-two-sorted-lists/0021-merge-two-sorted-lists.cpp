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
        ListNode* newNode = new ListNode();
        ListNode* newHead = newNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                // ListNode* temp = new ListNode(list1->val);
                // newNode->next = temp;
                newNode->next = list1;
                list1=list1->next;
            }
            else{
                // ListNode* temp = new ListNode(list2->val);
                // newNode->next = temp;   
                newNode->next = list2;             
                list2=list2->next;
            }
            newNode = newNode->next;
        }

        /*
        while(list1!=NULL){
            ListNode* temp = new ListNode(list1->val);
            newNode->next = temp;
            newNode = newNode->next;
            list1=list1->next;
        }
        while(list2!=NULL){
            ListNode* temp = new ListNode(list2->val);
            newNode->next = temp;
            newNode = newNode->next;
            list2=list2->next;
        }
        */

        if(list1!=NULL){
            //put the entire list (no need to do loop)
            newNode->next = list1;
        }
        else{
            newNode->next = list2;
        }
        return newHead->next;
    }
};