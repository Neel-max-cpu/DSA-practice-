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
    ListNode*reverse(ListNode*head){
        ListNode*curr = head;
        ListNode*prev = NULL;
        while(curr){
            ListNode*next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // reverse 2nd half of the list (keep 1st half big then 2nd half)
        ListNode*slow = head;
        ListNode*fast = head;        
        // 1 2 
        // 3 4 5 - 5, 4, 3

        // keep it 1 2 3 and 4 5

        // 1 2
        // 3 4 - 4 3

        // here to 1 2 3 and 4

        while(fast && fast->next){            
            slow = slow->next;
            fast = fast->next->next;
        }        

        ListNode*head2 = slow->next;
        slow->next = NULL; 

        ListNode*head1 = head;
        head2 = reverse(head2);
        // print(head2);

        while(head1 && head2){
            ListNode*next1 = head1->next;
            ListNode*next2 = head2->next;            

            head1->next = head2;
            if(next1){
                head2->next = next1;
            }
            else break;

            head1 = next1;
            head2 = next2;            
        }
    }

    private:
    void print(ListNode*head){
        ListNode*curr = head;
        while(curr){
            cout<<curr->val<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};