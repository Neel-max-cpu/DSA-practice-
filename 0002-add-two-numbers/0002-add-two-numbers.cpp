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
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        /*
        long long first_no = 0;
        long long second_no = 0;
        ListNode *temp = num1;
        long long multiplier = 1;
        while(temp != NULL){
            first_no += temp->val *multiplier;
            multiplier *= 10;
            temp = temp->next;
        }
        temp = num2;
        multiplier = 1;
        while(temp != NULL){
            second_no += temp->val *multiplier;
            multiplier *= 10;
            temp = temp->next;
        }
        long long total = first_no + second_no;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        if(total == 0){
            // edge case
            ListNode *head = new ListNode(0);
            return head;
        }
        while(total>0){
            long long temp = total%10;
            ListNode *newNode = new ListNode((int)temp);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
            total /= 10;
        }
        return head;

        */

        /*
        ListNode *l1 = num1;
        ListNode *l2 = num2;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int sum = 0;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int a = l1->val;
            int b = l2->val;
            sum  = a+b;
            
            if(carry>0){
                sum+=carry;
            }

            int put = sum%10;
            carry = sum/10;

            ListNode *newNode = new ListNode(put);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }

            l1 = l1->next;
            l2 = l2->next;
            sum = 0;
        }

        while(l1!= NULL){
            int a = l1->val;
            if(carry>0){
                a+=carry;
            }
            carry = a/10;
            int put = a%10;

            ListNode *newNode = new ListNode(put);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }

            l1 = l1->next;
        }
        
        while(l2!= NULL){
            int a = l2->val;
            if(carry>0){
                a+=carry;
            }
            carry = a/10;
            int put = a%10;

            ListNode *newNode = new ListNode(put);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
            
            l2 = l2->next;
        }

        if(carry>0){
            ListNode *newNode = new ListNode(1);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
        }

        return head;
        */
        
        ListNode *l1 = num1;
        ListNode *l2 = num2;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry>0){
            int sum = 0;
            int a = 0, b = 0;
            if(l1!=NULL){
                a = l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                b = l2->val;
                l2 = l2->next;
            }

            sum  = a+b;            
            if(carry>0){
                sum+=carry;
            }

            int put = sum%10;
            carry = sum/10;

            ListNode *newNode = new ListNode(put);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }
};